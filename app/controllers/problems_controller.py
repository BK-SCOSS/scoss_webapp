from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *

problems_controller = Blueprint('problems_controller', __name__)

@problems_controller.route('/api/problem', methods = ['GET', 'POST', 'PUT', 'DELETE'])
def problem():
    if request.method == 'GET':
        contest_name = request.args.get('contest_name')
        req = Problem.objects(contest_name=contest_name)
        res = []
        for data in req:
            temp = data.to_mongo()
            del temp['_id']
            res.append(temp)
        return jsonify({'problems': res}), 200
    if request.method == 'POST':
        try:
            problem_name =request.form['problem_name']
            contest_name = request.form['contest_name']
            data = Problem.objects(problem_name=problem_name)
            if len(data) > 0:
                for da in data:
                    if da.problem_name == problem_name and da.contest_name == contest_name:
                        return jsonify({'info': 'The problem name may already exist'}),400
            Problem(problem_name=problem_name, contest_name=contest_name).save()
            return jsonify({'problem_name': problem_name}), 200
        except Exception:
            return jsonify({'info': 'The problem name may already exist'}),400
    if request.method == 'PUT':
        # print(request.json)
        problem_name =request.json['problem_name']
        contest_name = request.json['contest_name']
        sources = request.json['sources']
        metrics = request.json['metrics']
        Problem.objects(problem_name=problem_name, contest_name=contest_name).update(sources=sources, metrics=metrics)
        return jsonify({'problem_name':problem_name}), 200
    if request.method == 'DELETE':
        problem_name= request.form['problem_name']
        Problem.objects(problem_name=problem_name).delete()
        info = 'Delete problem' + str(problem_name)
        return jsonify({'info': info})

@problems_controller.route('/api/problem_name', methods = ['GET'])
def problem_name():
    if request.method == 'GET':
        problem_name = request.args.get('problem_name')
        contest_name = request.args.get('contest_name')
        data = Problem.objects.get(contest_name=contest_name, problem_name=problem_name)
        res = []
        temp = data.to_mongo()
        del temp['_id']
        res.append(temp)
        return jsonify({'problem': res}), 200

@problems_controller.route('/api/problem_metric', methods = ['PUT'])
def problem_metric():
    problem_name =request.json['problem_name']
    contest_name = request.json['contest_name']
    metrics = request.json['metrics']
    Problem.objects(problem_name=problem_name, contest_name=contest_name).update(metrics=metrics)
    return jsonify({'problem_name':problem_name}), 200

@problems_controller.route('/api/update_matrix', methods = ['PUT'])
def update_matrix():
    problem_name =request.json['problem_name']
    contest_name = request.json['contest_name']
    similarity_matrix = request.json['similarity_matrix']
    aligment_matrix = request.json['aligment_matrix']
    Problem.objects(problem_name=problem_name, contest_name=contest_name).update(similarity_matrix=similarity_matrix, aligment_matrix=aligment_matrix)
    return jsonify({'problem_name':problem_name}), 200

@problems_controller.route('/api/update_matrix_smoss', methods = ['PUT'])
def update_matrix_smoss():
    problem_name =request.json['problem_name']
    contest_name = request.json['contest_name']
    similarity_matrix_smoss = request.json['similarity_matrix_smoss']
    aligment_matrix_smoss = request.json['aligment_matrix_smoss']
    Problem.objects(problem_name=problem_name, contest_name=contest_name).update(similarity_matrix_smoss=similarity_matrix_smoss, aligment_matrix_smoss=aligment_matrix_smoss)
    return jsonify({'problem_name':problem_name}), 200

@problems_controller.route('/api/get_problem')
def get_problem():
    contest_name = request.args.get('contest_name')
    problem_name = request.args.get('problem_name')
    req = Problem.objects(contest_name=contest_name, problem_name=problem_name)
    res = []
    for data in req:
        temp = data.to_mongo()
        del temp['_id']
        res.append(temp)
    return jsonify(res[0]), 200