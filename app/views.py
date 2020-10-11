import os
import sys
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(WORKING_DIR, './'))
from werkzeug.utils import secure_filename
from flask import Flask, render_template, url_for, request, redirect, session, jsonify
from scoss_api import mod
import requests
from scoss import Scoss
from app import db
from werkzeug.security import generate_password_hash, check_password_hash
UPLOAD_FILE = "./app/data/"
PATH_DATA = "./app/data/program.json"
METRIC_LIST  = ['count_operator', 'set_operator', 'hash_operator']
TEMPLATES = './app/templates'
URL = 'http://0.0.0.0:5005'
app = Flask(__name__)
app.register_blueprint(mod)
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'
app.config["MONGODB_HOST"] = 'mongodb://172.18.0.2:27017/scoss'
app.config["MONGODB_DATABASE"] = 'scoss'
db.init_app(app)
# program = []
@app.route('/login', methods=["GET", "POST"])
def login():
	if request.method == "GET":
		return render_template('login.html')
	else:
		session['logged_in'] = False 
		username = request.form['username']
		password = request.form['password']
		params = {'username': username}
		url = URL + '/api/user'
		req = requests.get(url=url, params=params)
		if 'password' in req.json().keys():
			if check_password_hash( req.json()['password'], password):
				session['username'] = username
				session['logged_in'] = True
				return redirect(url_for('index'))
			else:
				return render_template('login.html', info='wrong_pass')
		return render_template('login.html', info='wrong_user')
@app.route('/logout')
def logout():
	session.clear()
	return render_template('login.html', info='')

@app.route('/signup', methods=["GET", "POST"])
def signup():
	if request.method == "GET":
		return render_template('register.html')
	else:
		username = request.form['username']
		password = request.form['password']
		level = request.form['level']
		data = {'username': username , 'password': generate_password_hash(password), 'level':level}
		url = URL +'/api/user'
		req = requests.post(url=url, data=data)
		if 'user_id' not in req.json().keys():
			return jsonify({'info': 'False'})
		return jsonify({'info': 'True'})
		

@app.route('/')
def index():
	return render_template('index.html')

@app.route('/document')
def document():
	return render_template('document.html')

@app.route('/api')
def api():
	return render_template('api.html')

@app.route('/test')
def test():
	return render_template('test.html')

@app.route('/contest', methods=['GET', 'POST'])
def contest():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				contest_author = session['username']
				info = request.args.get('info')
				params = {'contest_author': contest_author}
				url = URL + '/api/contest'
				data = requests.get(url=url, params=params)
				print(data.json())
				return render_template('contest.html', data=data.json()['data'], info=info)
			else: 
				print(request.form)
				contest_name = request.form['contest_name']
				data_form = {'contest_name': contest_name, 'contest_author': session['username']}
				url = URL + '/api/contest'
				req = requests.post(url=url,data=data_form)
				if 'contest_name' in req.json().keys():
					return redirect(url_for('contest'))
				else:
					return redirect(url_for('contest', info='wrong'))
		else:
			return redirect(url_for('login'))
	else: 
		return redirect(url_for('login'))

@app.route('/problem', methods=['GET', 'POST'])
def problem():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				info = request.args.get('info')
				contest_name = request.args.get('contest_name')
				params = {'contest_name': contest_name}
				url = URL + '/api/problem'
				req = requests.get(url=url, params=params)
				return render_template('problem.html', contest_name=contest_name,info=info, data=req.json()['problems'])
			if request.method == 'POST':
				problem_name = request.form['problem_name']
				contest_name = request.args.get('contest_name')
				data = {'problem_name': problem_name, 'contest_name':contest_name}
				url = URL + '/api/problem'
				req = requests.post(url=url, data=data)
				print(req.json())
				if 'problem_name' in req.json().keys():
					return redirect(url_for('problem', contest_name=contest_name))
				else:
					return redirect(url_for('problem',contest_name=contest_name, info='wrong'))
	return redirect(url_for('login'))

@app.route('/source')
def source():
	return render_template('source.html')

@app.route('/res')
def res():
	return render_template('result.html')

if __name__ == "__main__":
	app.debug = True
	app.run(host='0.0.0.0', port=5005)