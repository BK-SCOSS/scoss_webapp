from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file, Blueprint
from scoss import Scoss
import json
import time
import os
from werkzeug.utils import secure_filename
import shutil



UPLOAD_FILE = "./app/data/"
PATH_DATA = "./app/data/program.json"
mod = Blueprint('scoss_api', __name__)
program = []
def read_json(pathfile):
    try:
        with open(pathfile, 'r') as json_file:
            data = json.loads(json_file.read())     
    except Exception:
        data = []
    return data
def save_json(pathfile, data):
    with open(pathfile, 'w') as json_file:
        json.dump(data, json_file, indent=4)
@mod.route('/api/create_scoss', methods=['POST'])
def create_scoss():
    try:
        idx = str(int(time.time()))
        datas = read_json(PATH_DATA)
        topic = {}
        topic['name'] = request.form['name']
        topic['description'] = request.form['description']
        topic['measures'] = json.loads(request.form['measures'])
        topic['idx'] = idx
        topic['members'] = {}
        datas.append(topic)
        sc = Scoss(idx, topic['measures'])
        program.append(sc)
        save_json(PATH_DATA, datas)
        path_dir = os.path.join(UPLOAD_FILE, idx)
        os.mkdir(path_dir)
    except Exception:
        return jsonify({'Error': "Can not create scoss"}), 400
    return jsonify({'idx': topic['idx']}), 200

@mod.route('/api/add_file', methods=['POST'])
def add_file():
    datas = read_json(PATH_DATA)
    username = request.form['username']
    id_scoss = request.form['id_scoss']
    for data in datas:
        for sc in program:
            if data['idx'] == str(id_scoss) and sc.get_idx_scoss() == str(id_scoss):
                if username not in data['members'].keys():
                    file = request.files['file']
                    path_dir = os.path.join(UPLOAD_FILE, id_scoss)
                    filepath = os.path.join(path_dir, secure_filename(file.filename))
                    file.save(filepath)
                    data['members'][username] = []
                    data['members'][username].append(filepath)
                    sc.add_file(filepath)
                else:
                    file = request.files['file']
                    path_dir = os.path.join(UPLOAD_FILE, id_scoss)
                    filepath = os.path.join(path_dir, secure_filename(file.filename))
                    file.save(filepath)
                    data['members'][username].append(filepath)
                    sc.add_file(filepath)
                save_json(PATH_DATA, datas)
                return jsonify({'info': 'True'}), 200
        
    return jsonify({'info': 'False'}), 400
                

@mod.route('/api/get_score', methods=["POST"])
def get_score():
    id_scoss = request.form['id_scoss']
    for sc in program:
        if sc.get_idx_scoss() == str(id_scoss):
            return jsonify(sc.get_score()), 200
    return jsonify({'Error': "Can not get score"}), 400

@mod.route('/api/delete_scoss', methods=["POST"])
def delete_scoss():
    id_scoss = request.form['id_scoss']
    datas = read_json(PATH_DATA)
    for data in datas:
        for sc in program:
            if data['idx'] == str(id_scoss) and sc.get_idx_scoss() == str(id_scoss):
                path_dir = os.path.join(UPLOAD_FILE, id_scoss)
                shutil.rmtree(path_dir, ignore_errors=True)
                datas.remove(data)
                program.remove(sc)
                save_json(PATH_DATA, datas)
                return jsonify({'info': 'Delete'}), 200
    return jsonify({'Error': "Can not delete"}), 400

