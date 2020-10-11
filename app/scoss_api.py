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
            level = data_user.level # 0-root 1-user
        except Exception:
            return jsonify({'info': "Account information is not correct"}), 400
        return jsonify({'user_id': user_id, 'username': username, 'password': password, 'level': level})
    if request.method == "POST":
        try:
            user_id = str(int(time.time()) * 1000)
            username = request.form['username']
            password = request.form['password']
            level = request.form['level']

            User(user_id=user_id, username=username, password=password, level=level).save()
        except Exception:
            return jsonify({'info': "The account name may already exist"}), 400
        return jsonify({'user_id': user_id})
    if request.method == "PUT":
        try:
            user_id = request.form['user_id']
            username = request.form['username']
            password = request.form['password']
            level = level
            data_user = User.objects(user_id=user_id).update(username=username, password=password, level=level)
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

@mod.route('/api/contest', methods=['GET', 'POST', 'PUT', 'DELETE'])
def contest():
    if request.method == 'GET':
        contest_author = request.args.get('contest_author')
        data = Contest.objects(contest_author=contest_author)
        res = []
        for da in data:
            temp = da.to_mongo()
            del temp['_id']
            res.append(temp)
        return jsonify({'contest_author': contest_author, 'data': res}),200
    if request.method == 'POST':
        try:
            contest_name = request.form['contest_name']
            contest_author = request.form['contest_author']
            data = Contest.objects(contest_name=contest_name)
            if len(data) >0:
                for da in data:
                    if da.contest_name == contest_name and da.contest_author == contest_author:
                        return jsonify({'info': 'The contest name may already exist'}),400
            Contest(contest_name=contest_name, contest_author=contest_author).save()
            return jsonify({'contest_name': contest_name}),200
        except Exception:
            return jsonify({'info': 'The contest name may already exist'}),400

    if request.method == 'PUT':
        contest_name = request.form['contest_name']
        contest_author = request.form['contest_author']
        Contest.objects(contest_name=contest_name).update(contest_author=contest_author)
        return jsonify({'socss_id': contest_name}),200
    if request.method == 'DELETE':
        contest_name = request.form['contest_name']
        Contest.objects(contest_name=contest_name).delete()
        info = 'Delete' + str(contest_name)
        return jsonify({'info': info}), 200

@mod.route('/api/problem', methods = ['GET', 'POST', 'PUT', 'DELETE'])
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

    if request.method == 'DELETE':
        problem_name= request.form['problem_name']
        Problem.objects(problem_name=problem_name).delete()
        info = 'Delete problem' + str(problem_name)
        return jsonify({'info': info})