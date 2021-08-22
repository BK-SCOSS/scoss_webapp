from flask import config, request, jsonify, Blueprint, Response
import time
from zipfile import ZipFile
from models.models import *
from config import URL, LANGUAGE_SUPPORT, API_URI_SR
import requests
from utils import make_unique
from flask_jwt_extended import jwt_required
contests_controller = Blueprint('contests_controller', __name__)

@contests_controller.route('/api/users/<user_id>/contests/add', methods=['POST'])
@jwt_required()
def add_contest(user_id):
    try:
        timestamp = str(int(time.time()))
        contest_id = make_unique(timestamp)
        contest_name = request.json['contest_name']
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
                del temp['_id']
                res.append(temp)
        else:
            #người dùng xem được các contest do mình tạo
            for data_contest in data_contests:
                temp = data_contest.to_mongo()
                if temp['user_id'] == user_id:
                    data_user = User.objects.get(user_id=user_id)
                    temp['username'] = data_user.username
                    del temp['_id']
                    res.append(temp)
                # elif temp['contest_status'] == Status.checked:
                #     data_user = User.objects.get(user_id=temp['user_id'])
                #     temp['username'] = data_user.username
                #     del temp['_id']
                #     res.append(temp)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'contests': res})

@contests_controller.route('/api/contests', methods=['GET'])
@jwt_required()
def contest():
    try:
        data_contests = Contest.objects()
        print(data_contests.count())
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            # print(temp['user_id'])
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
        contest_data = Contest.objects(contest_id=contest_id).only('contest_id', 'contest_name', 'contest_status', 'metrics').first()
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
        if ZipFile(request.files["file"], "r").testzip() is not None:
            return jsonify({"error":"Tệp zip bị hỏng"}),400
        with ZipFile(request.files['file'], 'r') as zf:
            zfile = zf.namelist()
            for file in zfile:
                if file.split('.')[-1] in LANGUAGE_SUPPORT:
                    if len(file.split('/')) > 2 and file.split('/')[-1] != '':
                        try:
                            source_str = zf.read(file).decode('utf-8')
                        except:
                            source_str = zf.read(file).decode('cp437')
                        if file.split('/')[-2] in contest_list:
                            data_doc = {
                                "pathfile": file.split('/')[-1],
                                "lang": file.split('.')[-1],
                                'mask': '',
                                'source_str': source_str
                            }
                            contest_list[file.split('/')[-2]].append(data_doc)
                        else:
                            contest_list[file.split('/')[-2]] = []
                            data_doc = {
                                "pathfile": file.split('/')[-1],
                                "lang": file.split('.')[-1],
                                'mask': '',
                                'source_str': source_str
                            }
                            contest_list[file.split('/')[-2]].append(data_doc)
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
    return jsonify({'contest_id': contest_id}), 200

@contests_controller.route('/api/contests/<contest_id>/run', methods = ['POST'])
@jwt_required()
def run_contest(contest_id):
    try:
        url_contest = '{}/api/contests/{}'.format(API_URI_SR, contest_id)
        metrics = request.json        
        Contest.objects(contest_id=contest_id).update(metrics=metrics['metrics'])
        data_problems = requests.get(url=url_contest, 
        headers={'Authorization': request.headers['Authorization']})
        doc_status = {
            "contest_status": Status.running
        }
        print("--------------------")
        url_status = '{}/api/contests/{}/status'.format(API_URI_SR, contest_id)
        req = requests.put(url=url_status, json=doc_status, \
            headers={'Authorization': request.headers['Authorization']})
        if req.status_code != 200:
            return jsonify(req.json()), 200
        for problem in data_problems.json()['problems']:
            problem_id = problem['problem_id']
            url_run = '{}/api/problems/{}/run'.format(API_URI_SR, problem_id)
            req = requests.post(url=url_run, json=metrics,\
                headers={'Authorization': request.headers['Authorization']})
            if req.status_code != 200:
                return jsonify(req.json()), 200
        return jsonify({'contest_id': contest_id}), 200
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400

@contests_controller.route('/api/contests/<contest_id>/results', methods = ['GET'])
def get_result(contest_id):
    try:
        data_problems = Problem.objects(contest_id=contest_id).only('problem_id', 'problem_name', 'problem_status', 'user_id').all()
        contest_res = []
        for problem in data_problems:
            problem_id = problem.problem_id
            url_res =  '{}/api/problems/{}/results'.format(API_URI_SR, problem_id)
            res = requests.get(url=url_res)
            contest_res.append(res.json())
        return jsonify({'contest_id': contest_id, 'results': contest_res}), 200
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400

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
            Problem.objects(problem_id=problem_id).update(problem_status=1, metrics=[],similarity_list=[],\
                        similarity_smoss_list=[], alignment_list=[], alignment_smoss_list=[])
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