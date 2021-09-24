from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
import time
from werkzeug.security import generate_password_hash, check_password_hash
from utils import make_unique
from models.models import *
from flask_jwt_extended import jwt_required

users_controller = Blueprint('users_controller', __name__)


@users_controller.route('/api/users', methods=['GET'])
@admin_required
@jwt_required()
def user():
    try:
        data_users = User.objects()
        res = []
        for data_user in data_users:
            temp = data_user.to_mongo()
            del temp['_id']
            del temp['password']
            res.append(temp)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'users': res})

@users_controller.route('/api/users/username', methods=['GET'])
@jwt_required()
def username():
    try:
        username = request.args.get('username')
        data_users = User.objects.get(username=username)
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'user_id':data_users.user_id, 'username': data_users.username, 'role':data_users.role})

@users_controller.route('/api/users/add', methods=['POST'])
@admin_required
@jwt_required()
def add_user():
    # create account
    try:
        timestamp = str(int(time.time()))
        user_id = make_unique(timestamp)
        username = request.json['username']
        password = request.json['password']
        role = request.json['role'] #0- admin , 1-user
        password = generate_password_hash(password)
        User(user_id=user_id, username=username, password=password, role=role).save()
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'user_id': user_id})

@users_controller.route('/api/users/<user_id>', methods=['GET'])
@jwt_required()
def get_user(user_id):
    try:
        data_user = User.objects.get(user_id=str(user_id))
        user_id = data_user.user_id
        username = data_user.username
        # password = data_user.password
        role = data_user.role # 0-root 1-user
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'user_id': user_id, 'username': username, 'role': role})

@users_controller.route('/api/users/<user_id>', methods=['PUT'])
@jwt_required()
def update_user(user_id):
    try:
        current_user = User.objects.get(user_id=str(user_id))
        email = request.json['email']
        old_password = request.json['old_password']
        new_password = generate_password_hash(request.json['new_password'])
        check_password = current_user.password
        if check_password_hash(check_password, old_password):
            current_user.update(email=email, password=new_password)
            info = 'Update infomation for user_id:' + user_id
        else:
            info = "Wrong password!"
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'info': info})

@users_controller.route('/api/users/<user_id>', methods=['DELETE'])
@admin_required
@jwt_required()
def delete_user(user_id):  
    try:
        User.objects(user_id=user_id).delete()
        info = 'Delete user_id:' + user_id
    except Exception as e:
        return jsonify({"error":"Exception: {}".format(e)}),400
    return jsonify({'info': info}),200
    