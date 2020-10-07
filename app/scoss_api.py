from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models import *


mod = Blueprint('scoss_api', __name__)

@mod.route('/api/user', methods=['GET', 'POST', 'PUT', 'DELETE'])
def create_user():
    if request.method == "GET":
        try:
            username = request.args.get('username')
            data_user = User.objects.get(username=username)
            user_id = data_user.user_id
            password = data_user.password
        except Exception:
            return jsonify({'info': "Account information is not correct"}), 400
        return jsonify({'user_id': user_id, 'username': username, 'password': password})
    if request.method == "POST":
        try:
            user_id = str(int(time.time()) * 1000)
            username = request.form['username']
            password = request.form['password']
            password = password
            User(user_id=user_id, username=username, password=password).save()
        except Exception:
            return jsonify({'info': "The account name may already exist"}), 400
        return jsonify({'user_id': user_id})
    if request.method == "PUT":
        try:
            user_id = request.form['user_id']
            username = request.form['username']
            password = request.form['password']
            password = password
            data_user = User.objects(user_id=user_id).update(username=username, password=password)
        except Exception:
            return jsonify({'info': "Can't update infomation"}), 400
        return jsonify({'user_id': user_id})
    if request.method == "DELETE":
        try:
            user_id = request.form['user_id']
            data_user = User.objects(user_id=user_id).delete()
            info = 'Delete user_id:' + user_id
        except Exception:
            return jsonify({'info': "Can't delete"}), 400
        return jsonify({'info': info}),200
    return jsonify({'info': "API not found"}),400

@mod.route('/api/scoss', methods=['GET', 'POST', 'PUT', 'DELETE'])
def scoss():
    if request.method == 'GET':
        scoss_id = request.args.get('scoss_id')
        data = ScossDb.objects.get(scoss_id=scoss_id)
        scoss_name = data.scoss_name
        return jsonify({'socss_id': scoss_id, 'scoss_name': scoss_name}),200
    if request.method == 'POST':
        scoss_id = request.form['scoss_id']
        scoss_name = request.form['scoss_name']
        ScossDb(scoss_id=scoss_id, scoss_name=scoss_name).save()
        return jsonify({'socss_id': scoss_id}),200
    if request.method == 'PUT':
        scoss_id = request.form['scoss_id']
        scoss_name = request.form['scoss_name']
        ScossDb.objects(scoss_id=scoss_id).update(scoss_name=scoss_name)
        return jsonify({'socss_id': scoss_id}),200
    if request.method == 'DELETE':
        scoss_id = request.form['scoss_id']
        ScossDb.objects(scoss_id=scoss_id).delete()
        info = 'Delete' + str(scoss_id)
        return jsonify({'info': info}), 200

@mod.route('/api/problem', methods = ['GET', 'POST', 'PUT', 'DELETE'])
def problem():
    if request.method == 'GET':
        problem_id = request.args.get('problem_id')
        data = Problem.objects.get(problem_id=problem_id)
        res = data.to_mongo()
        del res['_id']
        return jsonify(res), 200
    if request.method == 'POST':
        problem_id =request.form['problem_id']
        scoss_id = request.form['scoss_id']
        sources = request.form['sources']
        metrics = request.method['metrics']
        similarity_matrix = request.form['similarity_matrix']
        aligment_matrix = request.form['aligment_matrix']
        Problem(problem_id=problem_id, scoss_id=scoss_id, sources=sources, metrics=metricsm, similarity_matrix=similarity_matrix, aligment_matrix=aligment_matrix).save()
        return jsonify({'problem_id': problem_id})
    if request.method == 'PUT':
        problem_id =request.form['problem_id']
        scoss_id = request.form['scoss_id']
        sources = request.form['sources']
        metrics = request.method['metrics']
        similarity_matrix = request.form['similarity_matrix']
        aligment_matrix = request.form['aligment_matrix']
        Problem.objects(problem_id=problem_id).update(scoss_id=scoss_id, sources=sources, metrics=metrics, similarity_matrix=similarity_matrix, aligment_matrix=aligment_matrix)
        return jsonify({'problem_id': problem_id}), 200
    if request.method == 'DELETE':
        problem_id= request.form['problem_id']
        Problem.objects(problem_id=problem_id).delete()
        info = 'Delete problem' + str(problem_id)
        return jsonify({'info': info})