from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *

users_controller = Blueprint('users_controller', __name__)


@users_controller.route('/api/users', methods=['GET'])
def list_user():
    if request.method == "GET":
        list_user = User.objects()
        res = []
        for user in list_user:
            temp = user.to_mongo()
            del temp['_id']
            res.append(temp)
        return jsonify({'data': res, 'message': 'Get information succesfully!'}),200

@users_controller.route('/api/users/add', methods=['POST'])
def create_user():
    try:
        user_id = str(int(time.time()) * 1000)
        username = request.form['username']
        password = request.form['password']
        role = request.form['role'] #0- admin , 1-user
        User(user_id=user_id, username=username, password=password, role=role).save()
    except Exception:
        return jsonify({'message': "The account name may already exist"}), 400
    return jsonify({'message': 'Create user successfully!'})

@users_controller.route('/api/users/<string:username>', methods=['GET'])
def get_user_id(username):
    try:
        data_user = User.objects.get(username=username)
        password = data_user.password
        user_id =data_user.user_id
        role = data_user.role # 0-root 1-user
        # return  jsonify({'info': "Account information is not correct"}), 400
        return jsonify({'user_id': user_id, 'username': username, 'password': password, 'role': role}), 200
    except Exception:
        return jsonify({'message': 'Cannot get information'}), 400

@users_controller.route('/api/users/<string:user_id>', methods=['GET'])
def get_user(user_id):
    try:
        data_user = User.objects.get(user_id=user_id)
        username = data_user.username
        password = data_user.password
        role = data_user.role # 0-root 1-user
        # return  jsonify({'info': "Account information is not correct"}), 400
        return jsonify({'user_id': user_id, 'username': username, 'password': password, 'role': role}), 200
    except Exception:
        return jsonify({'message': 'Cannot get information'}), 400


@users_controller.route('/api/users/<string:user_id>', methods=['PUT'])
def update_user(user_id):
    try:
        password = request.form['password']
        data_user = User.objects(user_id=user_id).update(password=password)
        return jsonify({'message': 'Update succesfully!'}),200
    except Exception:
        return jsonify({'info': "Can't update infomation"}), 400

@users_controller.route('/api/users/<string:user_id>', methods=['DELETE'])
def delete_user(user_id):
    try:
        User.objects(user_id=user_id).delete()
        message = 'Delete user_id:' + user_id + 'successfully!'
    except Exception:
        return jsonify({'message': "Can't delete"}), 400
    return jsonify({'message': message}),200