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
test_api = Blueprint('test_api', __name__)

# some api for test page
@test_api.route('/api/project/<project_id>/from_zip', methods=['POST'])
def add_zip(project_id):
    """
    folder:
    ----file1.cpp
    ----file2.cpp
    ----file3.cpp
    """
    try:
        if ZipFile(request.files["file"], "r").testzip() is not None:
            return jsonify({"error":"The zip file is corrupted"}), 400
        # Kiểm tra xem test tồn tại chưa nếu chưa tạo mới 1 project có tên là test
        if Project.objects(project_id="test_scoss").count() == 0:
            project_status = Status.init
            Project(project_id=project_id, project_name="test", public_token="test",
                    project_status=project_status, metrics=list([])).save()
        data_project = Project.objects.get(project_id=project_id)
        sources = []
        project_status = Status.init
        with ZipFile(request.files['file'], 'r') as zf:
            zfiles = zf.namelist()
            if len(zfiles) > 50:
                return jsonify({"error": "Does not support testing greater than 50 files"}), 400
            supported_files = [f for f in zfiles if f.endswith(SUPPORTED_EXTENSIONS)] # Get the files with correct extensions
            if not supported_files:
                print("Problems: Wrong zip file's format", flush=True)
                return jsonify({"error": "Wrong zip file's format"}), 400
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
        Project.objects(project_id=project_id).update(sources=sources, project_status=project_status, metrics=list([]))
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200

@test_api.route('/api/project/<project_id>/run', methods=['POST'])
def run_source(project_id):
    try:
        # print(project_id)
        data_project = Project.objects.get(project_id=project_id)
        metrics = request.json['metrics']
        Project.objects(project_id=project_id).update(metrics=metrics)
        if not data_project.sources:
            return jsonify({"error": "No sources to run"}), 400
        if data_project.project_status not in [Status.running, Status.waiting]:
            doc_status = {
                "project_status": Status.waiting
            }
            url_status = "{}/api/project/{}/status".format(URL, str(project_id))
            req = requests.put(url=url_status, json=doc_status)
            if req.status_code != 200: 
                return jsonify(req.json()), 400
            # print(tq.count)
            # tq.empty()
            tq.enqueue(do_project, args=(project_id, JOB_TIMEOUT), job_timeout=1000)
        
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id}), 200

@test_api.route('/api/project/<project_id>/sources', methods=['GET'])
def get_source(project_id):
    try:
        source1 = request.args.get('source1')
        source2 = request.args.get('source2')
        sources = []
        for source in [source1, source2]:
            data_source = Project.objects(project_id=project_id).fields(sources={'$elemMatch': {'mask': source}})
            if len(data_source[0]['sources']) == 0:
                data_source = Project.objects.filter(project_id=project_id).fields(sources={'$elemMatch': {'pathfile': source}})
            temp = {
                'pathfile': data_source[0]['sources'][0]['pathfile'],
                'lang': data_source[0]['sources'][0]['lang'],
                'mask': data_source[0]['sources'][0]['mask'],
                'source_str': data_source[0]['sources'][0]['source_str'],
            }
            sources.append(temp)

    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'project_id': project_id, 'sources': sources}), 200

@test_api.route('/api/project/<project_id>/reset', methods=['PUT'])
def reset(project_id):
    """
    update project status
    """
    try:
        Project.objects(project_id=project_id).update(project_status=1, metrics=[])
        Result.objects(problem_id=project_id).delete()
        info = 'Reset all!'
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'info': info}), 200

@test_api.route('/api/project/<project_id>/status', methods=['GET'])
def get_status(project_id):
    try:
        data_project= Project.objects.get(project_id=project_id)
        data_doc = {
            'project_id': data_project.project_id,
            'project_name': data_project.project_name,
            'project_status': data_project.project_status
        }
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify(data_doc), 200

@test_api.route('/project/<project_id>/status/stream')
# @jwt_required()
def status(project_id):
    def check_status(project_id):
        data_project = Project.objects.get(project_id=project_id)
        yield 'data: {}\n\n'.format(data_project.project_status)
    return Response(check_status(project_id), mimetype="text/event-stream")