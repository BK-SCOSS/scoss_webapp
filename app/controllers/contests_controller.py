from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *

contests_controller = Blueprint('contests_controller', __name__)

@contests_controller.route('/api/users/<user_id>/contests/add', methods=['POST'])
def add_contest(user_id):
    try:
        contest_id = str(int(time.time()) * 1000)
        contest_name = request.json['contest_name']
        contest_status = 'init'
        data = Contest.objects(user_id=user_id, contest_name=contest_name)
        if len(data) > 0:
            return jsonify({'error': "The contest name may already exist"}), 400
        Contest(contest_id=contest_id, user_id=user_id, contest_name=contest_name, contest_status=contest_status).save()
    except Exception:
        return jsonify({'error': "Can't add contest"}), 400
    return jsonify({'contest_id': contest_id}),200

@contests_controller.route('/api/users/<user_id>/contests', methods=['GET'])
def get_contest_user(user_id):
    try:
        data_contests = Contest.objects(user_id=user_id)
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get contests!"}), 400
    return jsonify({'contests': res})

@contests_controller.route('/api/contests', methods=['GET'])
def contest():
    try:
        data_contests = Contest.objects()
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get contests!"}), 400
    return jsonify({'contests': res})


@contests_controller.route('/api/contests/<contest_id>', methods=['GET'])
def get_contest(contest_id):
    try:
        data_contests = Problem.objects(contest_id=contest_id)
        res = []
        for data_contest in data_contests:
            temp = data_contest.to_mongo()
            del temp['_id']
            res.append(temp)
    except Exception:
        return jsonify({'error': "Can't get contests!"}), 400
    return jsonify({'contest_id':contest_id,'problems': res})

@contests_controller.route('/api/contests/<contest_id>', methods=['DELETE'])
def delete_contest(contest_id):
    try:
        Contest.objects(contest_id=str(contest_id)).delete()
        info = 'Delete contest_id' + str(contest_id)
    except Exception:
        return jsonify({'error': "Can't delete contest!"}), 400
    return jsonify({'info':info})

    # if request.method == 'POST':
    #     try:
    #         contest_name = request.form['contest_name']
    #         contest_author = request.form['contest_author']
    #         data = Contest.objects(contest_name=contest_name)
    #         if len(data) >0:
    #             for da in data:
    #                 if da.contest_name == contest_name and da.contest_author == contest_author:
    #                     return jsonify({'info': 'The contest name may already exist'}),400
    #         Contest(contest_name=contest_name, contest_author=contest_author).save()
    #         return jsonify({'contest_name': contest_name}),200
    #     except Exception:
    #         return jsonify({'info': 'The contest name may already exist'}),400

    # if request.method == 'PUT':
    #     contest_name = request.form['contest_name']
    #     contest_author = request.form['contest_author']
    #     Contest.objects(contest_name=contest_name).update(contest_author=contest_author)
    #     return jsonify({'socss_id': contest_name}),200
    # if request.method == 'DELETE':
    #     contest_name = request.form['contest_name']
    #     Contest.objects(contest_name=contest_name).delete()
    #     info = 'Delete' + str(contest_name)
    #     return jsonify({'info': info}), 200
