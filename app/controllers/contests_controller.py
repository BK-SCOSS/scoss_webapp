from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *
from mongoengine.queryset.visitor import Q

contests_controller = Blueprint('contests_controller', __name__)



@contests_controller.route('/api/contests', methods=['GET'])
def contest():
    if request.method == 'GET':
        contest_author = request.args.get('contest_author')
        role = request.args.get('role')

        if int(role) == 0:
            list_contest = Contest.objects()
        else:
            list_contest = Contest.objects( Q(contest_status="checked") | Q(user_id=contest_author))
        
        res = []
        for da in list_contest:
            temp = da.to_mongo()
            del temp['_id']
            res.append(temp)
        return jsonify({'contest_author': contest_author, 'data': res, 'role': role}),200

@contests_controller.route('/api/contests/add', methods=['POST'])
def create_contest():
    if request.method == 'POST':
        try:
            contest_id = str(int(time.time()) * 1000)
            contest_name = request.form['contest_name']
            contest_author = request.form['contest_author']
            contest_status = "New"
            data = Contest.objects(contest_name=contest_name)
            if len(data) >0:
                for da in data:
                    if da.contest_name == contest_name and da.user_id == contest_author:
                        return jsonify({'info': 'The contest name may already exist'}),400
            Contest(contest_id=contest_id, contest_name=contest_name, user_id=contest_author, 
                    contest_status=contest_status).save()
            return jsonify({'contest_name': contest_name}),200
        except Exception:
            return jsonify({'info': 'The contest name may already exist'}),400

@contests_controller.route('/api/contests/<string:contest_id>', methods=['GET'])
def get_contest(contest_id):
    try:
        data = Problem.objects(contest_id=contest_id)
        for da in data:
            temp = da.to_mongo()
            del temp['_id']
            res.append(temp)
        return jsonify({'data': res}),200
    except Exception:
        return jsonify({'message': 'Cannot get information'}), 400

@contests_controller.route('/api/contests/<string:contest_id>', methods=['PUT'])
def edit_contest(contest_id):
    try:
        contest_name = request.form['contest_name']
        contest_status = request.form['contest_status']
        Contest.objects(contest_id=contest_id).update(contest_name=contest_name, contest_status=contest_status)
        return jsonify({'message': 'Update succesfully!'}),200
    except Exception:
        return jsonify({'message': 'Cannot update'}), 400
    
@contests_controller.route('/api/contests/<string:contest_id>', methods=['DELETE'])
def delete_contest(contest_id):
    try:
        Contest.objects(contest_id=contest_id).delete()
        info = 'Delete succesfully!'
        return jsonify({'info': info}), 200
    except Exception:
        info = 'Delete failure!'
        return jsonify({'info': info}), 404
    