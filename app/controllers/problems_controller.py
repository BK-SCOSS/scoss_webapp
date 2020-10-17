from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *
from zipfile import ZipFile
from controllers.task_queue import tq
problems_controller = Blueprint('problems_controller', __name__)

@problems_controller.route('/api/contests/<contest_id>/problems/add', methods = ['POST'])
def add_problem(contest_id):
    try:
        problem_id = str(int(time.time()) * 1000)
        problem_name = request.json['problem_name']
        problem_status = 'init'
        req = Contest.objects.get(contest_id=contest_id)
        contest_id = contest_id
        user_id = req.user_id
        data_problem = Problem.objects(user_id=user_id, contest_id=contest_id, problem_name=problem_name)
        if len(data_problem) > 0:
            return jsonify({'error': "The problem name may already exist"}), 400
        Problem(problem_id=problem_id, problem_name=problem_name, problem_status=problem_status, contest_id=contest_id, user_id=user_id).save()
        return jsonify({'problem_id': problem_id}), 200
    except Exception:
        return jsonify({'error': "Can't add problem"}), 400

@problems_controller.route('/api/contests/<contest_id>/problems', methods = ['GET'])
def problems(contest_id):
    try:
        data_problems = Problem.objects(contest_id=contest_id)
        res = []
        for data_problem in data_problems:
            temp = data_problem.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get problems!"}), 400
    return jsonify({'contest_id': contest_id,'problems': res}),200

@problems_controller.route('/api/problems/<problem_id>', methods = ['GET'])
def get_problem(problem_id):
    try:
        data_problem = Problem.objects.get(problem_id=problem_id)
        data_doc = {
            'problem_id': data_problem.problem_id,
            'problem_name': data_problem.problem_name,
            'contest_id': data_problem.contest_id,
            'user_id': data_problem.user_id,
            'sources': data_problem.sources,
            'metrics': data_problem.metrics
        }
    except Exception:
        return jsonify({'error': "Can't get problem!"}), 400
    return jsonify(data_doc),200

@problems_controller.route('/api/problems/<problem_id>', methods = ['DELETE'])
def delete_problem(problem_id):
    try:
        Problem(problem_id=problem_id).delete()
        info = 'Delete problem_id' + str(problem_id)
    except Exception:
        return jsonify({'error': "Can't delete problem!"}), 400
    return jsonify({'info':info})

@problems_controller.route('/api/problems/<problem_id>/status', methods = ['PUT'])
def updata_status(problem_id):
    try:
        problem_status = request.json['problem_status']
        Problem.objects(problem_id=problem_id).update(problem_status=problem_status)
    except Exception:
        return jsonify({'error': "Can't update problem_status!"}), 400
    return jsonify({'problem_id':problem_id}), 200

@problems_controller.route('/api/problems/<problem_id>/status', methods = ['GET'])
def get_status(problem_id):
    try:
        data_problem = Problem.objects.get(problem_id=problem_id)
        data_doc = {
            'problem_id': data_problem.problem_id,
            'problem_name': data_problem.problem_name,
            'problem_status': data_problem.problem_status
        }
    except Exception:
        return jsonify({'error': "Can't get problem_status!"}), 400
    return jsonify(data_doc),200

    
@problems_controller.route('/api/problems/<problem_id>/from_zip', methods = ['POST'])
def add_zip(problem_id):
    """
    folder:
    ----file1.cpp
    ----file2.cpp
    ----file3.cpp
    """
    try: 
        data_problem = Problem.objects.get(problem_id=problem_id)
        sources = data_problem.sources
        with ZipFile(request.files['file'], 'r') as zf:
            zfile = zf.namelist()
            for file in zfile:
                data_doc = {
                    "pathfile": file,
                    "lang": file.split('.')[-1],
                    'mask': '',
                    'source_str': zf.read(file).decode('utf-8')
                }
                sources.append(data_doc)
        Problem.objects(problem_id=problem_id).update(sources=sources)
    except Exception:
        return jsonify({"error":"Can't add from zip in problems"}),400
    return jsonify({'problem_id': problem_id}), 200

@problems_controller.route('/api/problems/<problem_id>/sources/add', methods = ['POST'])
def add_source(problem_id):
    try: 
        data_problem = Problem.objects.get(problem_id=problem_id)
        sources = data_problem.sources
        mask = request.form['mask']
        file = request.files['files']
        data_doc = {
            "pathfile": file.filename,
            "lang": file.filename.split('.')[-1],
            'mask': '',
            'source_str': file.read()
        }
        sources.append(data_doc)
        Problem.objects(problem_id=problem_id).update(sources=sources)
    except Exception:
        return jsonify({"error":"Can't add file in problems"}),400
    return jsonify({'problem_id': problem_id}), 200

@problems_controller.route('/api/contests/<contest_id>/problems/<problem_id>/results/scoss', methods = ['PUT'])
def update_result_scoss(problem_id):
    try: 
        similarity_list = request.json['similarity_list']
        alignment_list = request.json['alignment_list']
       
    except Exception:
        return jsonify({"error":"Can't run problem"}),400
    return jsonify({'problem_id': problem_id}), 200
@problems_controller.route('/api/problems/<problem_id>/run', methods = ['POST'])
def run_source(problem_id):
    # try: 
    data_problem = Problem.objects.get(problem_id=problem_id)
    metrics = request.json['metrics']
    Problem.objects(problem_id=problem_id).update(metrics=metrics)
    if len(data_problem) > 0:
        if data_problem.problem_status in ['init', 'checked']:
            tq.enqueue_nowait(problem_id)
    tq.join()
    # except Exception:
    #     return jsonify({"error":"Can't run problem"}),400
    return jsonify({'problem_id': problem_id}), 200