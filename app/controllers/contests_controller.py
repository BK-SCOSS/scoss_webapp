from flask import config, request, jsonify, Blueprint, Response
import time
from zipfile import ZipFile
from models.models import *
from mongoengine.queryset.visitor import Q
from config import URL, API_URI_SR, SUPPORTED_EXTENSIONS
import requests
from utils import make_unique
from flask_jwt_extended import jwt_required
import re

contests_controller = Blueprint('contests_controller', __name__)

@contests_controller.route('/api/users/<user_id>/contests/add', methods=['POST'])
@jwt_required()
def add_contest(user_id):
    try:
        timestamp = str(int(time.time()))
        contest_id = make_unique(timestamp)
        contest_name = request.json['contest_name']
        if contest_name == '':
            return jsonify({'error': "Contest name must not be empty"}),400
        contest_status = Status.init
        data = Contest.objects(user_id=user_id, contest_name=contest_name)
        if len(data) > 0:
            return jsonify({'error': "The contest name may already exist"}), 400
        Contest(contest_id=contest_id, user_id=user_id, contest_name=contest_name, contest_status=contest_status, metrics=list([])).save()
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'contest_id': contest_id}),200

@contests_controller.route('/api/users/<user_id>/contests', methods=['GET'])
@jwt_required()
def get_contest_user(user_id):
    try:
        data_contests = Contest.objects()
        res = []
        data_user = User.objects.get(user_id=user_id)
        role = data_user.role
        # admin xem có quyền xem tất cả các contest có trong hệ thống
        if str(role) == '0':
            for data_contest in data_contests:
                temp = data_contest.to_mongo()
                data_user = User.objects.get(user_id=user_id)
                temp['username'] = data_user.username
                temp['created_at'] = data_contest.created_at.strftime("%d/%m/%Y")
                del temp['_id']
                res.append(temp)
        else:
            #người dùng xem được các contest do mình tạo
            for data_contest in data_contests:
                temp = data_contest.to_mongo()
                if temp['user_id'] == user_id:
                    data_user = User.objects.get(user_id=user_id)
                    temp['username'] = data_user.username
                    temp['created_at'] = data_contest.created_at.strftime("%d/%m/%Y")
                    del temp['_id']
                    res.append(temp)
                # elif temp['contest_status'] == Status.checked:
                #     data_user = User.objects.get(user_id=temp['user_id'])
                #     temp['username'] = data_user.username
                #     del temp['_id']
                #     res.append(temp)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'data': res})

@contests_controller.route('/api/contests', methods=['GET'])
@jwt_required()
def contest():
    try:
        data_contests = Contest.objects()
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            if User.objects(user_id=temp['user_id']).count() == 0:
                continue
            data_user = User.objects(user_id=temp['user_id']).first()
            temp['username'] = data_user.username
            del temp['_id']
            res.append(temp)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'contests': res})

@contests_controller.route('/api/contests/<contest_id>', methods=['GET'])
@jwt_required()
def get_contest(contest_id):
    try:
        res = Problem.objects(contest_id=contest_id).only('problem_id', 'problem_name', 'problem_status', 'user_id')
        contest_data = Contest.objects(contest_id=contest_id).only('contest_id', 'contest_name', 'contest_status', 'metrics', 'user_id').first()
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'contest_id':contest_id, 'problems': res, 'contest_data': contest_data})

@contests_controller.route('/api/contests/<contest_id>', methods=['DELETE'])
@jwt_required()
def delete_contest(contest_id):
    try:
        Contest.objects(contest_id=str(contest_id)).delete()
        Problem.objects(contest_id=contest_id).delete()
        info = 'Delete contest_id' + str(contest_id)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'info':info})

@contests_controller.route('/api/contests/<contest_id>/status', methods=['PUT'])
@jwt_required()
def update_status(contest_id):
    try:
        contest_status = request.json['contest_status']
        Contest.objects(contest_id=contest_id).update(contest_status=contest_status)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'contest_id':contest_id}), 200

@contests_controller.route('/api/contests/<contest_id>/status', methods=['GET'])
@jwt_required()
def get_status(contest_id):
    try:
        data_contest = Contest.objects.get(contest_id=contest_id)
        data_doc = {
            'contest_id': data_contest.contest_id,
            'contest_name': data_contest.contest_name,
            'contest_status': data_contest.contest_status
        }
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify(data_doc),200

@contests_controller.route('/api/contests/<contest_id>/from_zip', methods = ['POST'])
@jwt_required()
def add_zip(contest_id):
    """
    folder:
    ----folder:
        ----file1.cpp
        ----file2.cpp
        ----file3.cpp
    """
    try: 
        contest_list = {}
        messages = []
        if ZipFile(request.files["file"], "r").testzip() is not None:
            return jsonify({"error":"The zip file is corrupted"}), 400
        with ZipFile(request.files['file'], 'r') as zf:
            zfiles = zf.namelist()
            supported_files = [f for f in zfiles if f.endswith(SUPPORTED_EXTENSIONS)] # Get the files with correct extensions
            if not supported_files or len(supported_files[0].split('/')) <= 2:
                print("Contest: Wrong zip file's format", flush=True)
                return jsonify({"error": "Wrong zip file's format"}), 400
            if len(supported_files) != len(zfiles):
                # zfiles contains some unsupported files: wrong extensions, wrong directories,...
                # Push some notification in the future
                unsupported_files = set(zfiles) - set(supported_files)
                print('Your zip file contains some unexpected files:', unsupported_files, flush=True)
                messages.append('Your zip file contains some unexpected files: {}'.format(unsupported_files))
            list_name_contain_space = []
            for file in supported_files:
                file_parts = file.split('/')
                filename = file_parts[-1]
                if ' ' in filename:
                    list_name_contain_space.append(filename)
                    filename = filename.replace(' ', '_')
                if len(file_parts) > 2 and filename != '':
                    try:
                        source_str = zf.read(file).decode('utf-8')
                    except:
                        source_str = zf.read(file).decode('cp437')
                    if file_parts[-2] in contest_list:
                        data_doc = {
                            "pathfile": filename,
                            "lang": filename.split('.')[-1],
                            'mask': filename,
                            'source_str': source_str
                        }
                        contest_list[file_parts[-2]].append(data_doc)
                    else:
                        contest_list[file_parts[-2]] = [
                            {
                                "pathfile": filename,
                                "lang": filename.split('.')[-1],
                                'mask': filename,
                                'source_str': source_str
                            }
                        ]
            if list_name_contain_space:
                print('These are spaces in your filename(s), we replace them with "_"', flush=True) # list_name_contain_space
                messages.append('These are spaces in your filename(s), we replace them with "_"')
        url_contest = '{}/api/contests/{}/problems/add'.format(URL, contest_id)
        for problem_key, problem_value in contest_list.items():
            req = requests.post(url=url_contest, json={'problem_name': problem_key},\
                headers={'Authorization': request.headers['Authorization']})
            if req.status_code != 200:
                return jsonify(req.json()), 200
            if 'problem_id' in req.json().keys():
                problem_id = req.json()['problem_id']
                data_problem = Problem.objects.get(problem_id=problem_id)
                sources = data_problem.sources
                for source in problem_value:
                    sources.append(source)
                Problem.objects(problem_id=problem_id).update(sources=sources)
            else:
                return jsonify({'error': req.json()['error']}), 400
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'contest_id': contest_id, 'messages': messages}), 200

@contests_controller.route('/api/contests/<contest_id>/run', methods = ['POST'])
@jwt_required()
def run_contest(contest_id):
    try:
        url_contest = '{}/api/contests/{}'.format(API_URI_SR, contest_id)
        metrics = request.json        
        Contest.objects(contest_id=contest_id).update(metrics=metrics['metrics'])
        data_problems = requests.get(url=url_contest, 
            headers={'Authorization': request.headers['Authorization']})
        problems = data_problems.json()['problems']
        if not problems:
            return jsonify({"error": "No problems to run"}), 400

        doc_status = {
            "contest_status": Status.running
        }
        print("--------------------")
        url_status = '{}/api/contests/{}/status'.format(API_URI_SR, contest_id)
        req = requests.put(url=url_status, json=doc_status, \
            headers={'Authorization': request.headers['Authorization']})
        if req.status_code != 200:
            return jsonify(req.json()), 200
        for problem in problems:
            problem_id = problem['problem_id']
            url_run = '{}/api/problems/{}/run'.format(API_URI_SR, problem_id)
            req = requests.post(url=url_run, json=metrics,\
                headers={'Authorization': request.headers['Authorization']})
            if req.status_code != 200:
                return jsonify(req.json()), 200
        return jsonify({'contest_id': contest_id}), 200
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400

# @contests_controller.route('/api/contests/<contest_id>/results', methods = ['GET'])
# def get_result(contest_id):
#     try:
#         data_problems = Problem.objects(contest_id=contest_id).only('problem_id', 'problem_name', 'problem_status', 'user_id').all()
#         contest_res = []
#         for problem in data_problems:
#             problem_id = problem.problem_id
#             url_res =  '{}/api/problems/{}/results'.format(API_URI_SR, problem_id)
#             res = requests.get(url=url_res)
#             contest_res.append(res.json())
#         return jsonify({'contest_id': contest_id, 'results': contest_res}), 200
#     except Exception as e:
#         return jsonify({"error":"Exception: {}".format(e)}),400

@contests_controller.route('/ajax/contests/<contest_id>/results', methods=['POST'])
def get_ajax_contest_results(contest_id):
    order_columns = ['problem_name', 'source1', 'source2', 'scores__count_operator', 'scores__hash_operator', 
        'scores__set_operator', 'scores__moss_score', 'scores__mean']
    draw = request.form['draw'] 
    start = int(request.form['start'])
    length = int(request.form['length'])
    searchValue = request.form["search[value]"]
    orderDirection = request.form["order[0][dir]"]
    orderColumn = request.form["order[0][column]"]
    data_problems = Problem.objects(contest_id=contest_id).only('problem_id', 'problem_name', 'problem_status', 'user_id').all()
    problem_dict = {}
    for problem in data_problems:
        problem_dict[problem.problem_id] = problem.problem_name

    totalRecords = Result.objects(problem_id__in=list(problem_dict.keys())).count()

    regex = re.compile('.*{}.*'.format(searchValue), re.IGNORECASE)
    totalRecordwithFilter = Result.objects.filter(Q(problem_id__in=list(problem_dict.keys())) & (Q(problem_name=regex)|Q(source1=regex)|Q(source2=regex))).count()

    order = order_columns[int(orderColumn)]
    if orderDirection == 'desc':
        order = '-' + order
    similarity_list = Result.objects.filter(Q(problem_id__in=list(problem_dict.keys())) & (Q(problem_name=regex)|Q(source1=regex)|Q(source2=regex))).\
        order_by(order).skip(start).limit(length)

    score_span = '<a href="/problems/{}/compare?source1={}&source2={}&metric={}" target="_blank"><span style="color:rgb({}, 0, 0);">{}%</span></a>'
    data = []
    for sim in similarity_list:
        problem_id = sim['problem_id']
        a_result = {'problem_name':problem_dict[problem_id], 
            'source1':sim['source1'], 'source2':sim['source2']}
        for metric, score in sim['scores'].items():
            if metric != 'mean':
                a_result[metric] = score_span.format(sim['problem_id'], sim['source1'], sim['source2'], metric, int(score*255), round(score*100, 2))
            else:
                a_result[metric] = '<span style="color:rgb({}, 0, 0);">{}%</span>'.format(int(score*255), round(score*100, 2))
        data.append(a_result)
    return jsonify({'draw': draw, 'iTotalRecords': totalRecords, 'iTotalDisplayRecords': totalRecordwithFilter, 'data':data}), 200

@contests_controller.route('/api/contests/<contest_id>/results', methods = ['PUT'])
def update_result(contest_id):
    try:
        data = request.json['data']
        Contest.objects(contest_id=contest_id).update(results=data)
        return jsonify({'contest_id': contest_id, 'status': 'Success'}), 200
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400

@contests_controller.route('/api/contests/<contest_id>/check_status', methods = ['GET'])
@jwt_required()
def check_status(contest_id):
    try:
        data_problems = Problem.objects(contest_id=contest_id)
        status = Status.init
        res = []
        for data_problem in data_problems:
            temp = data_problem.to_mongo()
            res.append(temp['problem_status'])
        status = min(res)
        Contest.objects(contest_id=contest_id).update(contest_status=status)
        return jsonify({'info': 'status update was successful'}), 200
    except Exception:
        return jsonify({"error":"Can't update status contest"}),400

@contests_controller.route('/api/contests/<contest_id>/reset', methods=['PUT'])
@jwt_required()
def reset(contest_id):
    try:
        problem_list = Problem.objects(contest_id=contest_id).only('problem_id')
        for problem in problem_list:
            problem_id = problem.problem_id
            Problem.objects(problem_id=problem_id).update(problem_status=1, metrics=[])
            Result.objects(problem_id=problem_id).delete()
        Contest.objects(contest_id=contest_id).update(contest_status=1, metrics=[])
        info = 'Reset all!'
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'info': info}), 200

@contests_controller.route('/contests/<contest_id>/status')
# @jwt_required()
def status(contest_id):
	def check_status(contest_id):
		data_contest = Contest.objects.get(contest_id=contest_id)
		yield 'data: {}\n\n'.format(data_contest.contest_status)
	return Response(check_status(contest_id), mimetype="text/event-stream")
