from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
from werkzeug.security import generate_password_hash
import shutil
from models.models import *

users_controller = Blueprint('users_controller', __name__)


@users_controller.route('/api/users', methods=['GET'])
def user():
    try:
        data_users = User.objects()
        res = []
        for data_user in data_users:
            temp = data_user.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'users': res})

@users_controller.route('/api/users/username', methods=['GET'])
def username():
    try:
        username = request.args.get('username')
        data_users = User.objects.get(username=username)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'user_id':data_users.user_id, 'username': data_users.username, 'password': data_users.password, 'role':data_users.role})

@users_controller.route('/api/users/add', methods=['POST'])
def add_user():
    # create account
    try:
        if len(Counter.objects) == 0:
            user_id = 0
            Counter(name='count', count_user=0, count_problem=0, count_contest=0).save()
        else:
            user_id = Counter.objects.get(name='count').count_user + 1
            Counter.objects(name='count').update(count_user=user_id)
            user_id += 1
        user_id = str(user_id)
        username = request.json['username']
        password = request.json['password']
        role = request.json['role'] #0- admin , 1-user
        password = generate_password_hash(password)
        User(user_id=user_id, username=username, password=password, role=role).save()
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'user_id': user_id})

@users_controller.route('/api/users/<user_id>', methods=['GET'])
def get_user(user_id):
    try:
        data_user = User.objects.get(user_id=str(user_id))
        user_id = data_user.user_id
        username = data_user.username
        password = data_user.password
        role = data_user.role # 0-root 1-user
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'user_id': user_id, 'username': username, 'password': password, 'role': role})

@users_controller.route('/api/users/<user_id>', methods=['PUT'])
def update_user(user_id):
    try:
        password = generate_password_hash(request.json['password'])
        User.objects(user_id=str(user_id)).update(password=password)
        info = 'Update infomation for user_id:' + user_id
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'info': info})

@users_controller.route('/api/users/<user_id>', methods=['DELETE'])
def delete_user(user_id):  
    try:
        User.objects(user_id=user_id).delete()
        info = 'Delete user_id:' + user_id
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'info': info}),200
    