from controllers.users_controller import user
from flask import config, request, jsonify, Blueprint, Response
import time
from zipfile import ZipFile
from models.models import *
from config import URL, LANGUAGE_SUPPORT, API_URI_SR
import requests
from utils import make_unique
from flask_jwt_extended import jwt_required


public_api = Blueprint('public_api', __name__)

@public_api.route("/api/users/<user_id>/create_token")
@jwt_required()
def create_token(user_id):
    timestamp = str(int(time.time()))
    public_token = make_unique(timestamp)
    User.objects(user_id=user_id).update(public_token=public_token)
    return jsonify({"success": "True", "public_token": public_token}), 200

@public_api.route("/api/users/<user_id>/token")
@jwt_required()
def get_token(user_id):
    data_user = User.objects(user_id=user_id).first()
    public_token = data_user.public_token
    if public_token != None and public_token != "delete":
        return jsonify({"success": "True", "public_token": public_token}), 200
    return jsonify({"success": "False", "error": "Token không tồn tại"}), 400

@public_api.route("/api/users/<user_id>/delete_token", methods=["DELETE"])
@jwt_required()
def delete_token(user_id):
    public_token = "delete"
    User.objects(user_id=user_id).update(public_token=public_token)
    return jsonify({"success": "True"}), 200

# @public_api.route("/api/test")
# def 

