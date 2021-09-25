from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from flask_jwt_extended import create_access_token
from flask_jwt_extended import get_jwt
from flask_jwt_extended import jwt_required
from werkzeug.security import generate_password_hash, check_password_hash
from models.models import *
from controllers.task_queue import r
from flask_jwt_extended import JWTManager
from datetime import timedelta
import time 
from utils import make_unique
# from run import jwt
TTL = timedelta(hours=1)
jwt = JWTManager()
login_controller = Blueprint('login_controller', __name__)

# Callback function to check if a JWT exists in the redis blocklist
@jwt.token_in_blocklist_loader
def check_if_token_is_revoked(jwt_header, jwt_payload):
    jti = jwt_payload["jti"]
    token_in_redis = r.get(jti)
    return token_in_redis is not None

@login_controller.route('/api/signup', methods=['POST'])
def sign_up():
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


@login_controller.route('/api/login', methods=['POST'])
def login():
    try:
        username = request.json['username']
        password = request.json['password']
        data_user = User.objects.get(username=username)
        data = data_user.to_mongo()
        if check_password_hash(data['password'], password):
            # session['username'] = username
            del data['password']
            del data['_id']
            token = create_access_token(identity=data)
        else:
            return jsonify({"error": "Account password is not correct"}), 400
    except Exception as e:
        return jsonify({"error": "Exception: {}".format(e)}), 400
    return jsonify({'success': 'ok', 'user_id': data['user_id'], "username": data['username'], "role": data["role"], "token": token}), 200


@login_controller.route('/api/logout')
@jwt_required()
def logout():
    jti = get_jwt()["jti"]
    r.set(jti, "", ex=TTL)
    return jsonify({'message': 'You successfully logged out'})

# @login_controller.route('/api/test')
# @jwt_required()
# def test():
#     return jsonify({'message': 'You successfully logged out'})