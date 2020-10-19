from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from zipfile import ZipFile
from models.models import *
from config import URL
import requests

contests_controller = Blueprint('contests_controller', __name__)

@contests_controller.route('/api/users/<user_id>/contests/add', methods=['POST'])
def add_contest(user_id):
    try:
        contest_id = str(int(time.time()) * 1000)
        contest_name = request.json['contest_name']
        contest_status = 'init'
        data = Contest.objects(user_id=user_id, contest_name=contest_name)
        if len(data) > 0:
            return jsonify({'error': "The contest name may already exist"}), 400
        Contest(contest_id=contest_id, user_id=user_id, contest_name=contest_name, contest_status=contest_status).save()
    except Exception:
        return jsonify({'error': "Can't add contest"}), 400
    return jsonify({'contest_id': contest_id}),200

@contests_controller.route('/api/users/<user_id>/contests', methods=['GET'])
def get_contest_user(user_id):
    try:
        data_contests = Contest.objects(user_id=user_id)
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get contests!"}), 400
    return jsonify({'contests': res})

@contests_controller.route('/api/contests', methods=['GET'])
def contest():
    try:
        data_contests = Contest.objects()
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get contests!"}), 400
    return jsonify({'contests': res})


@contests_controller.route('/api/contests/<contest_id>', methods=['GET'])
def get_contest(contest_id):
    try:
        data_contests = Problem.objects(contest_id=contest_id)
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get contests!"}), 400
    return jsonify({'contest_id':contest_id,'problems': res})

@contests_controller.route('/api/contests/<contest_id>', methods=['DELETE'])
def delete_contest(contest_id):
    try:
        Contest.objects(contest_id=str(contest_id)).delete()
        info = 'Delete contest_id' + str(contest_id)
    except Exception:
        return jsonify({'error': "Can't delete contest!"}), 400
    return jsonify({'info':info})
@contests_controller.route('/api/contests/<contest_id>/status', methods=['PUT'])
def update_status(contest_id):
    try:
        contest_status = request.json['contest_status']
        Contest.objects(contest_id=contest_id).update(contest_status=contest_status)
    except Exception:
        return jsonify({'error': "Can't update contest_status!"}), 400
    return jsonify({'contest_id':contest_id}), 200

@contests_controller.route('/api/contests/<contest_id>/status', methods=['GET'])
def get_status(contest_id):
    try:
        data_contest = Contest.objects.get(contest_id=contest_id)
        data_doc = {
            'contest_id': data_contest.contest_id,
            'contest_name': data_contest.contest_name,
            'contest_status': data_contest.contest_status
        }
    except Exception:
        return jsonify({'error': "Can't get contest_status!"}), 400
    return jsonify(data_doc),200

@contests_controller.route('/api/contests/<contest_id>/from_zip', methods = ['POST'])
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
        with ZipFile(request.files['file'], 'r') as zf:
            zfile = zf.namelist()
            for file in zfile:
                if len(file.split('/')) > 2 and file.split('/')[-1] != '':
                    if file.split('/')[1] in contest_list:
                        data_doc = {
                            "pathfile": file.split('/')[-1],
                            "lang": file.split('.')[-1],
                            'mask': '',
                            'source_str': zf.read(file).decode('utf-8')
                        }
                        contest_list[file.split('/')[1]].append(data_doc)
                    else:
                        contest_list[file.split('/')[1]] = []
                        data_doc = {
                            "pathfile": file.split('/')[-1],
                            "lang": file.split('.')[-1],
                            'mask': '',
                            'source_str': zf.read(file).decode('utf-8')
                        }
                        contest_list[file.split('/')[1]].append(data_doc)
        url_contest = URL + '/api/contests/'+contest_id+'/problems/add'
        for problem_key, problem_value in contest_list.items():
            req = requests.post(url=url_contest, json={'problem_name': problem_key})
            if 'problem_id' in req.json().keys():
                problem_id = req.json()['problem_id']
                data_problem = Problem.objects.get(problem_id=problem_id)
                sources = data_problem.sources
                for source in problem_value:
                    sources.append(source)
                Problem.objects(problem_id=problem_id).update(sources=sources)
            else:
                return jsonify({'error': "The problem name may already exist"}), 400
    except Exception:
        return jsonify({"error":"Can't add from zip in contest"}),400
    return jsonify({'contest_id': contest_id}), 200

@contests_controller.route('/api/contests/<contest_id>/run', methods = ['POST'])
def run_contest(contest_id):
    try:
        url_contest = URL + '/api/contests/' + str(contest_id)
        metrics = request.json
        data_problems = requests.get(url=url_contest)
        doc_status = {
            "contest_status": "waiting"
        }
        url_status = URL + '/api/contests/'+str(contest_id)+'/status'
        requests.put(url=url_status, json=doc_status)
        for problem in data_problems.json()['problems']:
            problem_id = problem['problem_id']
            url_run = URL + '/api/problems/'+problem_id+'/run'
            requests.post(url=url_run, json=metrics)
        return jsonify({'contest_id': contest_id}), 200
    except Exception:
        return jsonify({"error":"Can't run contest"}),400

@contests_controller.route('/api/contests/<contest_id>/results', methods = ['GET'])
def get_result(contest_id):
    try:
        url_contest = URL + '/api/contests/' + str(contest_id)
        data_problems = requests.get(url=url_contest)
        contest_res = []
        for problem in data_problems.json()['problems']:
            problem_id = problem['problem_id']
            url_res = URL + '/api/problems/'+problem_id+'/results'
            res = requests.get(url=url_res)
            contest_res.append(res.json())
        return jsonify({'contest_id': contest_id, 'results': contest_res}), 200
    except Exception:
        return jsonify({"error":"Can't get result's contest"}),400