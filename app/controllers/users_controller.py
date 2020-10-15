from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *

users_controller = Blueprint('users_controller', __name__)


@users_controller.route('/api/user', methods=['GET', 'POST', 'PUT', 'DELETE'])
def create_user():
    if request.method == "GET":
        # get username password
        try:
            username = request.args.get('username')
            data_user = User.objects.get(username=username)
            user_id = data_user.user_id
            password = data_user.password
            role = data_user.role # 0-root 1-user
        except Exception:
            return jsonify({'info': "Account information is not correct"}), 400
        return jsonify({'user_id': user_id, 'username': username, 'password': password, 'role': role})
    if request.method == "POST":
        # create account
        try:
            user_id = str(int(time.time()) * 1000)
            username = request.form['username']
            password = request.form['password']
            role = request.form['role'] #0- admin , 1-user
            User(user_id=user_id, username=username, password=password, role=role).save()
        except Exception:
            return jsonify({'info': "The account name may already exist"}), 400
        return jsonify({'user_id': user_id})
    if request.method == "PUT":
        try:
            user_id = request.form['user_id']
            username = request.form['username']
            password = request.form['password']
            role = role
            data_user = User.objects(user_id=user_id).update(username=username, password=password, role=role)
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



