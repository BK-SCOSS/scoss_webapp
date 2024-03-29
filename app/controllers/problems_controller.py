from flask import Flask, render_template, url_for, request, redirect, \
    session, jsonify, send_file, Blueprint, stream_with_context, Response
from models.models import *
from mongoengine.queryset.visitor import Q
from zipfile import ZipFile
from config import API_URI, API_URI_SR, URL
from controllers.similarity_checker import do_job
from controllers.task_queue import tq
# from models.models import Status
from flask_jwt_extended import jwt_required
from utils import make_unique
import time
import requests
import config
import copy
import re
import json

problems_controller = Blueprint('problems_controller', __name__)


@problems_controller.route('/api/contests/<contest_id>/problems/add', methods=['POST'])
@jwt_required()
def add_problem(contest_id):
    try:
        timestamp = str(int(time.time()))
        problem_id = make_unique(timestamp)
        problem_name = request.json['problem_name']
        if problem_name == '':
            return jsonify({'error': "Problem name must not be empty"}), 400
        problem_status = Status.init
        req = Contest.objects.get(contest_id=contest_id)
        contest_id = contest_id
        user_id = req.user_id
        data_problem = Problem.objects(
            user_id=user_id, contest_id=contest_id, problem_name=problem_name)
        if len(data_problem) > 0:
            return jsonify({'error': "The problem name may already exist"}), 400
        Problem(problem_id=problem_id, problem_name=problem_name,
                problem_status=problem_status, contest_id=contest_id, user_id=user_id, metrics=list([])).save()
        return jsonify({'problem_id': problem_id}), 200
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400


@problems_controller.route('/api/contests/<contest_id>/problems', methods=['GET'])
@jwt_required()
def problems(contest_id):
    try:
        data_problems = Problem.objects(contest_id=contest_id)
        metrics = Contest.objects(contest_id=contest_id).first().metrics
        res = []
        for data_problem in data_problems:
            temp = data_problem.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'contest_id': contest_id, 'problems': res, 'metrics':metrics}), 200


@problems_controller.route('/api/problems/<problem_id>', methods=['GET'])
@jwt_required()
def get_problem(problem_id):
    try:
        data_problem = Problem.objects.get(problem_id=problem_id)
        contest_name = Contest.objects.get(
            contest_id=data_problem.contest_id).contest_name
        data_doc = {
            'problem_id': data_problem.problem_id,
            'problem_name': data_problem.problem_name,
            'problem_status': data_problem.problem_status,
            'contest_id': data_problem.contest_id,
            'contest_name': contest_name,
            'user_id': data_problem.user_id,
            'sources': data_problem.sources,
            'metrics': data_problem.metrics,
        }
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(data_doc), 200

@problems_controller.route('/api/problems/<problem_id>/get_alignment', methods=['POST'])
@jwt_required()
def get_alignment(problem_id):
    source1 = request.json['source1']
    source2 = request.json['source2']
    # metric = request.json['metric']
    result = Result.objects(problem_id=problem_id, source1=source1, source2=source2)
    return jsonify({'result':result}), 200

@problems_controller.route('/api/problems/<problem_id>', methods=['DELETE'])
@jwt_required()
def delete_problem(problem_id):
    try:
        Problem.objects(problem_id=problem_id).delete()
        info = 'Delete problem_id ' + str(problem_id)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'info': info})

@problems_controller.route('/api/problems/<problem_id>/status', methods=['PUT'])
@jwt_required()
def updata_status(problem_id):
    try:
        problem_status = request.json['problem_status']
        Problem.objects(problem_id=problem_id).update(
            problem_status=problem_status)
        contest_id = Problem.objects.get(problem_id=problem_id).contest_id
        requests.get(url="{}/api/contests/{}/check_status".format(API_URI_SR, contest_id),
        headers={'Authorization': request.headers['Authorization']})
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'problem_id': problem_id}), 200


@problems_controller.route('/api/problems/<problem_id>/status', methods=['GET'])
@jwt_required()
def get_status(problem_id):
    try:
        data_problem = Problem.objects.get(problem_id=problem_id)
        data_doc = {
            'problem_id': data_problem.problem_id,
            'problem_name': data_problem.problem_name,
            'problem_status': data_problem.problem_status
        }
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(data_doc), 200


@problems_controller.route('/api/problems/<problem_id>/from_zip', methods=['POST'])
@jwt_required()
def add_zip(problem_id):
    """
    folder:
    ----file1.cpp
    ----file2.cpp
    ----file3.cpp
    """
    try:
        if ZipFile(request.files["file"], "r").testzip() is not None:
            return jsonify({"error":"The zip file is corrupted"}), 400
        data_problem = Problem.objects.get(problem_id=problem_id)
        sources = data_problem.sources
        messages = []
        with ZipFile(request.files['file'], 'r') as zf:
            zfiles = zf.namelist()
            supported_files = [f for f in zfiles if f.endswith(config.SUPPORTED_EXTENSIONS)] # Get the files with correct extensions
            if not supported_files:
                print("Problems: Wrong zip file's format", flush=True)
                return jsonify({"error": "Wrong zip file's format"}), 400
            if len(supported_files) != len(zfiles):
                # zfiles contains some unsupported files: wrong extensions, wrong directories,...
                # Push some notification in the future
                unsupported_files = set(zfiles) - set(supported_files)
                print('Your zip file contains some unexpected files:', unsupported_files, flush=True)
                messages.append('Your zip file contains some unexpected files: {}'.format(unsupported_files))
            list_name_contain_space = []
            for file in supported_files:
                try:
                    source_str = zf.read(file).decode('utf-8')
                except:
                    source_str = zf.read(file).decode('cp437')
                file_parts = file.split('/')
                filename = file_parts[-1]
                if ' ' in filename:
                    list_name_contain_space.append(filename)
                    filename = filename.replace(' ', '_')
                if len(file_parts) > 1 and filename != '':
                    data_doc = {
                        "pathfile": filename,
                        "lang": filename.split('.')[-1],
                        'mask': filename,
                        'source_str': source_str
                    }
                    sources.append(data_doc)
            if list_name_contain_space:
                print('These are spaces in your filename(s), we replace them with "_"', flush=True) # list_name_contain_space
                messages.append('These are spaces in your filename(s), we replace them with "_"')
        Problem.objects(problem_id=problem_id).update(sources=sources)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'problem_id': problem_id, 'messages': messages}), 200


@problems_controller.route('/api/problems/<problem_id>/sources/add', methods=['POST'])
@jwt_required()
def add_source(problem_id):
    try:
        mask = request.form['mask']
        file = request.files['files']
        filename = file.filename
        extension = filename.split('.')[-1]
        messages = []
        if mask == '':
            return jsonify({'error': "Source name must not be empty"}), 400

        if '.{}'.format(extension) not in config.SUPPORTED_EXTENSIONS:
            return jsonify({'error': "'{}' extension is not supported yet".format(extension)}), 400

        data_problem = Problem.objects.get(problem_id=problem_id)
        sources = data_problem.sources
        exist_masks = set([source['mask'] for source in sources])
        
        if ' ' in mask:
            print('These are spaces in your filename, we replace them with "_"', flush=True)
            messages.append('These are spaces in your filename(s), we replace them with "_"')
            mask = mask.replace(' ', '_')

        if mask in exist_masks:
            return jsonify({'error': "Source name '{}' already exists".format(mask)}), 400
        
        data_doc = {
            "pathfile": filename,
            "lang": extension,
            'mask': mask,
            'source_str': file.read().decode('UTF-8')
        }
        sources.append(data_doc)
        Problem.objects(problem_id=problem_id).update(sources=sources)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'problem_id': problem_id, 'messages': messages}), 200

@problems_controller.route('/api/problems/<problem_id>/sources/delete_all', methods=['DELETE'])
@jwt_required()
def delete_all_sources(problem_id):
    try:
        Problem.objects(problem_id=problem_id).update(sources=[])
        info = 'Delete all sources!'
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'info': info})

# @problems_controller.route('/api/problems/<problem_id>/results', methods=['GET'])
# def get_results(problem_id):
#     try:
#         data_problem = Problem.objects.get(problem_id=problem_id)
#         problem_name = data_problem.problem_name
#         similarity_list = Result.objects(problem_id=problem_id)
#         result_list= []
#         for sim in similarity_list:
#             total = 0
#             num_of_score = 0
#             for score in sim['scores'].values():
#                 total += score
#                 num_of_score += 1
#             a_result = {'source1':sim['source1'], 'source2':sim['source2'], 'scores':sim['scores']}
#             if num_of_score != 0:
#                 a_result['scores']['mean'] = total/num_of_score
#             result_list.append(a_result)
#     except Exception as e:
#         return jsonify({"error": "Exception: {}".format(e)}), 400 
#     return jsonify({'problem_id': problem_id, 'results': result_list, 'problem_name': problem_name}), 200

@problems_controller.route('/ajax/problems/<problem_id>/results', methods=['POST'])
def get_ajax_problem_results(problem_id):
    order_columns = ['source1', 'source2']
    order_columns += ['scores__{}'.format(m['name']) for m in json.loads(request.form['metrics'])]
    order_columns.append('scores__mean')
    draw = request.form['draw'] 
    start = int(request.form['start'])
    length = int(request.form['length'])
    searchValue = request.form["search[value]"]
    orderDirection = request.form["order[0][dir]"]
    orderColumn = request.form["order[0][column]"]

    totalRecords = Result.objects(problem_id=problem_id).count()

    regex = re.compile('.*{}.*'.format(searchValue), re.IGNORECASE)
    totalRecordwithFilter = Result.objects.filter(Q(problem_id=problem_id) & (Q(source1=regex)|Q(source2=regex))).count()

    order = order_columns[int(orderColumn)]
    if orderDirection == 'desc':
        order = '-' + order
    similarity_list = Result.objects.filter(Q(problem_id=problem_id) & (Q(source1=regex)|Q(source2=regex))).\
        order_by(order).skip(start).limit(length)

    score_span = '<a href="/problems/{}/compare?source1={}&source2={}&metric={}" target="_blank"><span style="color:rgb({}, 0, 0);">{}%</span></a>'
    data = []
    for sim in similarity_list:
        a_result = {'source1':sim['source1'], 'source2':sim['source2']}
        for metric, score in sim['scores'].items():
            if metric != 'mean':
                a_result[metric] = score_span.format(problem_id, sim['source1'], sim['source2'], metric, int(score*255), round(score*100, 2))
            else:
                a_result[metric] = '<span style="color:rgb({}, 0, 0);">{}%</span>'.format(int(score*255), round(score*100, 2))
        data.append(a_result)
    return jsonify({'draw': draw, 'iTotalRecords': totalRecords, 'iTotalDisplayRecords': totalRecordwithFilter, 'data':data}), 200

@problems_controller.route('/api/problems/<problem_id>/results', methods=['PUT'])
@jwt_required()
def update_result(problem_id):
    try:
        result_list = request.json['result_list']
        for result in result_list:
            result_id = problem_id + '_' + result['source1'] + '_' + result['source2']
            scores = result['scores']
            scores['mean'] = sum(list(scores.values()))/len(scores)
            Result.objects(result_id=result_id).update_one(
                set__problem_id=problem_id, 
                set__problem_name=request.json['problem_name'], 
                set__source1=result['source1'], 
                set__source2=result['source2'], 
                set__scores=scores, 
                set__smoss_alignment=result['smoss_alignment'], 
                upsert=True)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'problem_id': problem_id}), 200

@problems_controller.route('/api/problems/<problem_id>/run', methods=['POST'])
@jwt_required()
def run_source(problem_id):
    try:
        # print(problem_id)
        Result.objects(problem_id=problem_id).delete()
        data_problem = Problem.objects.get(problem_id=problem_id)
        metrics = request.json['metrics']
        Problem.objects(problem_id=problem_id).update(metrics=metrics)
        url_status = "{}/api/problems/{}/status".format(URL, str(problem_id))
        if not data_problem.sources:
            # return jsonify({"error": "No sources to run"}), 400
            req = requests.put(url=url_status, json={"problem_status": Status.checked},\
                headers={'Authorization': request.headers['Authorization']})
            if req.status_code != 200: 
                return jsonify(req.json()), 400
            return jsonify({'problem_id': problem_id}), 200
        if data_problem.problem_status not in [Status.running, Status.waiting]:
            doc_status = {
                "problem_status": Status.waiting
            }
            req = requests.put(url=url_status, json=doc_status,\
                headers={'Authorization': request.headers['Authorization']})
            if req.status_code != 200: 
                return jsonify(req.json()), 400
            # print(tq.count)
            # tq.empty()
            tq.enqueue(do_job, args=(problem_id, data_problem.problem_name, request.headers['Authorization'], config.JOB_TIMEOUT), job_timeout=1000)
        
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'problem_id': problem_id}), 200

@problems_controller.route('/api/problems/<problem_id>/sources', methods=['GET'])
@jwt_required()
def get_source(problem_id):
    try:
        source1 = request.args.get('source1')
        source2 = request.args.get('source2')
        sources = []
        for source in [source1, source2]:
            data_source = Problem.objects(problem_id=problem_id).fields(sources={'$elemMatch': {'mask': source}})
            if len(data_source[0]['sources']) == 0:
                data_source = Problem.objects.filter(problem_id=problem_id).fields(sources={'$elemMatch': {'pathfile': source}})
            temp = {
                'pathfile': data_source[0]['sources'][0]['pathfile'],
                'lang': data_source[0]['sources'][0]['lang'],
                'mask': data_source[0]['sources'][0]['mask'],
                'source_str': data_source[0]['sources'][0]['source_str'],
            }
            sources.append(temp)

    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'problem_id': problem_id, 'sources': sources}), 200

@problems_controller.route('/api/problems/<problem_id>/reset', methods=['PUT'])
@jwt_required()
def reset(problem_id):
    try:
        Problem.objects(problem_id=problem_id).update(problem_status=1, metrics=[])
        Result.objects(problem_id=problem_id).delete()
        contest_id = Problem.objects.get(problem_id=problem_id).contest_id
        requests.get(url="{}/api/contests/{}/check_status".format(API_URI_SR, contest_id),
        headers={'Authorization': request.headers['Authorization']})
        info = 'Reset all!'
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'info': info}), 200

@problems_controller.route('/problems/<problem_id>/status')
# @jwt_required()
def status(problem_id):
    def check_status(problem_id):
        data_problem = Problem.objects.get(problem_id=problem_id)
        yield 'data: {}\n\n'.format(data_problem.problem_status)

    return Response(check_status(problem_id), mimetype="text/event-stream")

# @problems_controller.route('/api/test')
# def test():
#     return jsonify({"test": "123"})
