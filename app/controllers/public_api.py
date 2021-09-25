from requests.models import requote_uri
from controllers.users_controller import user
from flask import config, request, jsonify, Blueprint, Response
import time
from zipfile import ZipFile
from models.models import *
from config import URL, SUPPORTED_EXTENSIONS, API_URI_SR, JOB_TIMEOUT
import requests
from utils import make_unique
# from config import *
from flask_jwt_extended import jwt_required
from controllers.task_queue import tq
from controllers.similarity_project import do_project
from uuid import uuid4
import jwt
import re
from mongoengine.queryset.visitor import Q
KEY = "scoss_web_2020"
public_api = Blueprint('public_api', __name__)

@public_api.route("/api/users/<user_id>/create_token")
@jwt_required()
def create_token(user_id):
    """
    Tạo token public được lưu lại ở db
    """
    if User.objects(user_id=user_id).count() == 0:
        return jsonify({"success": "False"})
    # check public token 
    data_user = User.objects(user_id=user_id).first()
    timestamp = str(int(time.time()))
    data_encode = {
        "user_id":  data_user.user_id,
        "username": data_user.username,
        "timestamp": timestamp
    }
    public_token = jwt.encode(data_encode, KEY, algorithm="HS256")
    if public_token != None and public_token != 'delete':
        if Project.objects(public_token=data_user.public_token).count() > 0:
            data_projects = Project.objects(public_token=data_user.public_token).all()
            for data_project in data_projects:
                data_project.update(public_token=public_token)

    # print(public_token)
    User.objects(user_id=user_id).update(public_token=public_token)
    return jsonify({"success": "True", "public_token": public_token}), 200

@public_api.route("/api/users/<user_id>/token")
@jwt_required()
def get_token(user_id):
    """
    lấy thông tin token public
    """
    data_user = User.objects(user_id=user_id).first()
    public_token = data_user.public_token
    if public_token != None and public_token != "delete":
        return jsonify({"success": "True", "public_token": public_token}), 200
    return jsonify({"success": "False", "error": "Token does not exist"}), 400

@public_api.route("/api/users/<user_id>/delete_token", methods=["DELETE"])
@jwt_required()
def delete_token(user_id):
    """
    Thu hồi token public
    """
    public_token = User.objects(user_id=user_id).first().public_token
    # print()
    if public_token != None and public_token != 'delete':
        Project.objects(public_token=public_token).delete()
        public_token = "delete"
        User.objects(user_id=user_id).update(public_token=public_token)
        return jsonify({"success": "True"}), 200
    return jsonify({"success": "False", "error": "Token does not exist"}), 200

@public_api.route("/api/project", methods=["POST"])
def add_project():
    """
    Thêm 1 project mới của người dùng api public từ tệp zip
    """
    try:
        timestamp = str(int(time.time()))
        project_id = make_unique(timestamp)
        public_token = request.args.get("public_token")
        if User.objects(public_token=public_token).count() == 0:
            return jsonify({"success": "False", "error": "public token does not exist!"})
        project_name = request.form['project_name']
        metrics = []
        if 'set_operator' in request.form.keys():
            set_operator = float(request.form['set_operator'])
            metrics.append({
                "name": "set_operator",
                "threshold": set_operator
            })
        if 'hash_operator' in request.form.keys():
            hash_operator = float(request.form['hash_operator'])
            metrics.append({
                "name": "hash_operator",
                "threshold": hash_operator
            })
        if 'count_operator' in request.form.keys():
            count_operator = float(request.form['count_operator'])
            metrics.append({
                "name": "count_operator",
                "threshold": count_operator
            })
        if 'moss_score' in request.form.keys():
            moss_score = float(request.form['moss_score'])
            metrics.append({
                "name": "moss_score",
                "threshold": moss_score
            })           
        if len(metrics) == 0:
            return jsonify({"success": "False", "error": "No metrics"})  
        if public_token != None and public_token != "delete":
            # metrics = request.form['metrics']
            if ZipFile(request.files["file"], "r").testzip() is not None:
                return jsonify({"error":"Tệp zip bị hỏng"}),400
            sources = []
            project_status = Status.waiting
            with ZipFile(request.files['file'], 'r') as zf:
                zfiles = zf.namelist()
                supported_files = [f for f in zfiles if f.endswith(SUPPORTED_EXTENSIONS)] # Get the files with correct extensions
                if len(supported_files) != len(zfiles):
                    # zfiles contains some unsupported files: wrong extensions, wrong directories,...
                    # Push some notification in the future
                    unsupported_files = set(zfiles) - set(supported_files)
                    print('Your zip file contains some unexpected files:', unsupported_files, flush=True)
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
            Project(project_id=project_id, public_token=public_token, project_name=project_name,
                project_status=project_status, metrics=metrics, sources=sources).save()
            tq.enqueue(do_project, args=(project_id, JOB_TIMEOUT), job_timeout=1000)
        else:
            return jsonify({"error": "Token không tồn tại"}), 400
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id, "url_result": "{}/project/{}/results".format(API_URI_SR, project_id)}), 200
@public_api.route('/api/project', methods=['GET'])
def get_project():
    """
    Lấy thông tin các project mà người sử dung api public up lên hệ thống
    """
    try:
        public_token = request.args.get("public_token")
        # print(public_token)
        data_projects = Project.objects(public_token=public_token)
        print(data_projects.count())
        res = []
        for data_project in data_projects:
            data_doc = {
                'project_id': data_project.project_id,
                'project_status': data_project.project_status,
                'project_name': data_project.project_name,
                'sources': data_project.sources,
                'metrics': data_project.metrics
            }
            res.append(data_doc)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(res), 200

@public_api.route('/api/project/<project_id>', methods=['GET'])
def get_project_id(project_id):
    """
    Lấy thông tin 1 project
    """
    try:
        data_project = Project.objects.get(project_id=project_id)
        data_doc = {
            'project_id': data_project.project_id,
            'project_name': data_project.project_name,
            'project_status': data_project.project_status,
            'sources': data_project.sources,
            'metrics': data_project.metrics
        }
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(data_doc), 200

@public_api.route('/api/project/<project_id>', methods=['DELETE'])
def delete_project_id(project_id):
    """
    Xóa project
    """
    try:
        if Project.objects(project_id=project_id).count() > 0:
            data_project = Project.objects(project_id=project_id).delete()
        else:
            return jsonify({"error": "Not project!"}), 400
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({"success": "True"}), 200

@public_api.route('/api/project/<project_id>/status', methods=['PUT'])
def updata_status(project_id):
    try:
        project_status = request.json['project_status']
        Project.objects(project_id=project_id).update(
            project_status=project_status)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200

@public_api.route('/api/project/<project_id>/results', methods=['PUT'])
def update_result(project_id):
    try:
        result_list = request.json['result_list']
        for result in result_list:
            result_id = project_id + '_' + result['source1'] + '_' + result['source1']
            scores = result['scores']
            scores['mean'] = sum(list(scores.values()))/len(scores)
            Result.objects(result_id=result_id).update_one(
                set__problem_id=project_id, 
                set__source1=result['source1'], 
                set__source2=result['source2'], 
                set__scores=scores, 
                set__smoss_alignment=result['smoss_alignment'], 
                upsert=True)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200

@public_api.route('/api/project/<project_id>/results', methods=['GET'])
def get_results(project_id):
    try:
        data_project = Project.objects.get(project_id=project_id)
        project_name = data_project.project_name
        similarity_list = Result.objects(problem_id=project_id)
        result_list= []
        url_alignment = []
        for sim in similarity_list:
            total = 0
            num_of_score = 0
            for score in sim['scores'].values():
                total += score
                num_of_score += 1
            for metric in sim['scores'].keys():
                if metric != 'mean':
                    url_alignment.append({
                        'metric': metric,
                        'url_alignment': "{}/project/{}/compare?source1={}&source2={}&metric={}".format(API_URI_SR,
                        project_id, sim['source1'], sim['source2'], metric)
                    })
            a_result = {'source1':sim['source1'], 'source2':sim['source2'], 'scores':sim['scores'], "url_alignment": url_alignment}
            if num_of_score != 0:
                a_result['scores']['mean'] = total/num_of_score
            result_list.append(a_result)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400 
    return jsonify({'project_id': project_id, 'results': result_list, 'project_name': project_name, "project_status": data_project.project_status}), 200

@public_api.route('/ajax/project/<project_id>/results', methods=['POST'])
def get_ajax_project_results(project_id):
    data_project = Project.objects.get(project_id=project_id)
    order_columns = ['source1', 'source2', 'scores__count_operator', 'scores__hash_operator', 
        'scores__set_operator', 'scores__moss_score', 'scores__mean']
    draw = request.form['draw'] 
    start = int(request.form['start'])
    length = int(request.form['length'])
    searchValue = request.form["search[value]"]
    orderDirection = request.form["order[0][dir]"]
    orderColumn = request.form["order[0][column]"]
    totalRecords = Result.objects(problem_id=project_id).count()

    regex = re.compile('.*{}.*'.format(searchValue), re.IGNORECASE)
    totalRecordwithFilter = Result.objects.filter(Q(problem_id=project_id) & (Q(source1=regex)|Q(source2=regex))).count()

    order = order_columns[int(orderColumn)-1]
    if orderDirection == 'desc':
        order = '-' + order
    similarity_list = Result.objects.filter(Q(problem_id=project_id) & (Q(source1=regex)|Q(source2=regex))).\
        order_by(order).skip(start).limit(length)

    score_span = '<a href="/project/{}/compare?source1={}&source2={}&metric={}" target="_blank"><span style="color:rgb({}, 0, 0);">{}%</span></a>'
    data = []
    for sim in similarity_list:
        a_result = {'source1':sim['source1'], 'source2':sim['source2']}
        for metric, score in sim['scores'].items():
            if metric != 'mean':
                a_result[metric] = score_span.format(project_id, sim['source1'], sim['source2'], metric, int(score*255), round(score*100, 2))
            else:
                a_result[metric] = '<span style="color:rgb({}, 0, 0);">{}%</span>'.format(int(score*255), round(score*100, 2))
        data.append(a_result)
    return jsonify({'draw': draw, 'iTotalRecords': totalRecords, 'iTotalDisplayRecords': totalRecordwithFilter, 'data':data, 'status': data_project.project_status}), 200

@public_api.route('/api/project/<project_id>/get_alignment', methods=['POST'])
def get_alignment(project_id):
    source1 = request.json['source1']
    source2 = request.json['source2']
    # metric = request.json['metric']
    result = Result.objects(problem_id=project_id, source1=source1, source2=source2)
    return jsonify({'result':result}), 200

