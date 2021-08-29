from requests.models import requote_uri
from controllers.users_controller import user
from flask import config, request, jsonify, Blueprint, Response
import time
from zipfile import ZipFile
from models.models import *
from config import URL, LANGUAGE_SUPPORT, API_URI_SR, JOB_TIMEOUT
import requests
from utils import make_unique
# from config import *
from flask_jwt_extended import jwt_required
from controllers.task_queue import tq
from controllers.similarity_project import do_project
from uuid import uuid4
public_api = Blueprint('public_api', __name__)

@public_api.route("/api/users/<user_id>/create_token")
# @jwt_required()
def create_token(user_id):
    timestamp = str(int(time.time()))
    public_token = uuid4().hex+timestamp
    print(public_token)
    User.objects(user_id=user_id).update(public_token=public_token)
    return jsonify({"success": "True", "public_token": public_token}), 200

@public_api.route("/api/users/<user_id>/token")
@jwt_required()
def get_token(user_id):
    data_user = User.objects(user_id=user_id).first()
    public_token = data_user.public_token
    if public_token != None and public_token != "delete":
        return jsonify({"success": "True", "public_token": public_token}), 200
    return jsonify({"success": "False", "error": "Token does not exist"}), 400

@public_api.route("/api/users/<user_id>/delete_token", methods=["DELETE"])
@jwt_required()
def delete_token(user_id):
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
    try:
        timestamp = str(int(time.time()))
        project_id = make_unique(timestamp)
        public_token = request.args.get("public_token")
        set_operator = float(request.form['set_operator'])
        hash_operator = float(request.form['hash_operator'])
        count_operator = float(request.form['count_operator'])
        moss_score = float(request.form['moss_score'])
        metrics = [
            {
                "name": "set_operator",
                "threshold": set_operator
            },
                    {
                "name": "hash_operator",
                "threshold": hash_operator
            },
                    {
                "name": "count_operator",
                "threshold": count_operator
            },
                    {
                "name": "moss_score",
                "threshold": moss_score
            }
        ]
        if public_token != None and public_token != "delete":
            check_token = User.objects(public_token=public_token).count()
            if check_token != 0:
                # metrics = request.form['metrics']
                if ZipFile(request.files["file"], "r").testzip() is not None:
                    return jsonify({"error":"Tệp zip bị hỏng"}),400
                sources = []
                project_status = Status.waiting
                with ZipFile(request.files['file'], 'r') as zf:
                    zfile = zf.namelist()
                    for file in zfile:
                        if file.split('.')[-1] in LANGUAGE_SUPPORT:
                            try:
                                source_str = zf.read(file).decode('utf-8')
                            except:
                                source_str = zf.read(file).decode('cp437')
                            if len(file.split('/')) > 1 and file.split('/')[-1] != '':
                                data_doc = {
                                    "pathfile": file.split('/')[-1],
                                    "lang": file.split('.')[-1],
                                    'mask': '',
                                    'source_str': source_str
                                }
                                sources.append(data_doc)
                Project(project_id=project_id, public_token=public_token,
                    project_status=project_status, metrics=metrics, sources=sources).save()
                tq.enqueue(do_project, args=(project_id, JOB_TIMEOUT), job_timeout=1000)
        else:
            return jsonify({"error": "Token không tồn tại"}), 400
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200


# url_scoss = "{}/api/projects/{}/results/scoss".format(config.API_URI_SR, str(project_id))
# url_smoss = "{}/api/projects/{}/results/smoss".format(config.API_URI_SR, str(project_id))

@public_api.route('/api/project', methods=['GET'])
def get_project():
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
                'sources': data_project.sources,
                'metrics': data_project.metrics
            }
            res.append(data_doc)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(res), 200

@public_api.route('/api/project/<project_id>', methods=['GET'])
def get_project_id(project_id):
    try:
        data_project = Project.objects.get(project_id=project_id)
        data_doc = {
            'project_id': data_project.project_id,
            'project_status': data_project.project_status,
            'sources': data_project.sources,
            'metrics': data_project.metrics
        }
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(data_doc), 200


@public_api.route('/api/project/<project_id>/status', methods=['PUT'])
def updata_status(project_id):
    try:
        project_status = request.json['project_status']
        Project.objects(project_id=project_id).update(
            project_status=project_status)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200

@public_api.route('/api/project/<project_id>/results/scoss', methods=['PUT'])
def update_result_scoss(project_id):
    try:
        similarity_list = request.json['similarity_list']
        alignment_list = request.json['alignment_list']
        Project.objects(project_id=project_id).update(
            similarity_list=similarity_list, alignment_list=alignment_list)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200


@public_api.route('/api/project/<project_id>/results/smoss', methods=['PUT'])
def update_result_smoss(project_id):
    try:
        similarity_smoss_list = request.json['similarity_smoss_list']
        alignment_smoss_list = request.json['alignment_smoss_list']
        Project.objects(project_id=project_id).update(
            similarity_smoss_list=similarity_smoss_list, alignment_smoss_list=alignment_smoss_list)
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200



@public_api.route('/api/project/<project_id>/results', methods=['GET'])
def get_results(project_id):
    try:
        data_project = Project.objects.get(project_id=project_id)
        project_status = data_project.project_status
        similarity_list = data_project.similarity_list
        similarity_smoss_list = data_project.similarity_smoss_list
        metrics = data_project.metrics
        metric_list = []
        res = {}
        moss_threshold = 0
        for metric in metrics:
            metric_list.append(metric['name'])
            if metric['name'] == 'moss_score':
                moss_threshold = metric['threshold']

        if 'moss_score' in metric_list:
            for simi_smoss in similarity_smoss_list:
                key = hash(simi_smoss['source1']) ^ hash(simi_smoss['source2'])
                if simi_smoss['scores']['moss_score'] > moss_threshold:
                    temp_list = simi_smoss
                    res[key] = temp_list
                
            if len(metric_list) > 1:
                for simi in similarity_list:
                    key = hash(simi['source1']) ^ hash(simi['source2'])
                    if key in res.keys():
                        for metric in metric_list:
                            if metric != 'moss_score':
                                res[key]['scores'][metric] = simi['scores'][metric]
            for k in list(res):
                if len(res[k]['scores']) == 1:
                    if 'moss_score' in res[k]['scores'].keys():
                        del res[k]
        else:
            for simi in similarity_list:
                key = hash(simi['source1']) ^ hash(simi['source2'])
                temp_list = simi
                res[key] = temp_list
        check_zero = 0
        for key in res:
            total = 0
            num_of_score = 0
            if len(res[key]) == 0:
                check_zero += 1
                continue
            for score in res[key]['scores']:
                total += res[key]['scores'][score]
                num_of_score += 1
            if num_of_score != 0:
                res[key]['scores']['mean'] = total/num_of_score
        if(len(res.keys()) == check_zero):
            return jsonify({'project_id': project_id, 'results': [], 'project_status': project_status}), 200
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id, 'results': list(res.values()), 'project_status': project_status}), 200