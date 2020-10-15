from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil
from models.models import *

contests_controller = Blueprint('contests_controller', __name__)



@contests_controller.route('/api/contest', methods=['GET', 'POST', 'PUT', 'DELETE'])
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
