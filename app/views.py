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
app.config["MONGODB_HOST"] = 'mongodb://172.18.0.3:27017/scoss'
app.config["MONGODB_DATABASE"] = 'scoss'
db.init_app(app)
# program = []
@app.route('/login', methods=["GET", "POST"])
def login():
	if request.method == "GET":
		return render_template('login.html')
	else:
		username = request.form['username']
		password = request.form['password']
		params = {'username': username}
		url = URL + '/api/user'
		req = requests.get(url=url, params=params)
		if 'password' in req.json().keys():
			return jsonify({'check': check_password_hash( req.json()['password'], password)})
		return jsonify({'info': 'flase'})
@app.route('/logout')
def logout():
	return render_template('login.html', info='')

@app.route('/signup', methods=["GET", "POST"])
def signup():
	if request.method == "GET":
		return render_template('register.html')
	else:
		username = request.form['username']
		password = request.form['password']
		data = {'username': username , 'password': generate_password_hash(password)}
		url = URL +'/api/user'
		req = requests.post(url=url, data=data)
		if 'user_id' not in req.json().keys():
			return jsonify({'info': 'False'})
		return jsonify({'info': 'True'})
		

@app.route('/')
def index():
	return render_template('login.html')

@app.route('/home')
def home():
	author = request.args.get('author')
	return render_template('index.html', author=author)


@app.route('/contest', methods=['GET', 'POST'])
def contest():
	# if request.method == 'GET':
	error = request.args.get('error')
	author = 'tranvien98'
	query = {'author': author}
	data_contest = my_db.find_db('contest', query)
	return render_template('contest.html', data_contest=data_contest, author=author ,error=error)
	
@app.route('/add_contest', methods=['POST'])
def add_contest():
	ids = request.form['id-contest']
	name = request.form['name']
	author = request.form['author']
	contest_doc = {
		'id_contest': ids,
		'name': name,
		'author': author
	}
	id_query = {'id_contest': ids}
	# print(contest_doc)
	res = my_db.insert_db('contest',contest_doc , id_query)
	if res == False:
		return redirect(url_for('.contest', error = 'error_ids'))
	return redirect(url_for('.contest'))


@app.route('/problem', methods=['GET', 'POST'])
def problem():
	id_contest = request.args.get('id_contest')
	if request.method == 'GET':
		error = request.args.get('error')
		query = {'id_contest': id_contest}
		data_problem = my_db.find_db('problem', query)
		print(data_problem)
		return render_template('problem.html', data_problem=data_problem, id_contest=id_contest, error =error)
	else:
		problem_name = request.form['problem']
		problem_doc = {
			'id_contest': id_contest,
			'problem_name': problem_name,
			'source': [],
			'result': []
		}
		id_query = {'problem_name': problem_name}
		res = my_db.insert_db('problem',problem_doc , id_query)
		if res == False:
			return redirect(url_for('.problem', error = 'error_ids'))
		return redirect(url_for('.problem', id_contest=id_contest))


@app.route('/source', methods=['GET', 'POST'])
def source():
	problem_name = request.args.get('problem_name')
	if request.method == 'GET':
		query = {'problem_name': problem_name}
		data_problem = my_db.find_db('problem', query)
		# print(data_problem)
		return render_template('source.html', data_problem=data_problem[0])
	else:
		query = {'problem_name': problem_name}
		data_problem = my_db.find_db('problem', query)
		id_contest = data_problem[0]['id_contest']
		source = data_problem[0]['source']
		file = request.files['file']
		path_dir = os.path.join(UPLOAD_FILE, str(id_contest))
		if not os.path.exists(path_dir):
			os.mkdir(path_dir)
		path_dir = os.path.join(path_dir, str(problem_name))
		if not os.path.exists(path_dir):
			os.mkdir(path_dir)
		filepath = os.path.join(path_dir, secure_filename(file.filename))
		file.save(filepath)
		if filepath not in source:
			source.append(filepath)
		my_db.update_db('problem',query, data={'source': source})
		return redirect(url_for('source', problem_name=problem_name))

@app.route('/similarity', methods=["POST"])
def similarity():
	if request.method == "POST":
		problem_name = request.args.get('problem_name')
		query = {'problem_name': problem_name}
		data_problem = my_db.find_db('problem', query)
		source = data_problem[0]['source']
		lang = source[0].split('.')[-1]
		metric_list = []
		for metric in request.form:
			if metric in METRIC_LIST:
				metric_list.append(metric)
		sc = Scoss(lang=lang)
		for metric in metric_list:
			if request.form[metric] != '':
				sc.add_metric(metric, int(request.form[metric])/100)
			else:
				sc.add_metric(metric)
		for path in source:
			sc.add_file(path)
		res = sc.get_matches(and_thresholds=True)
		my_db.update_db('problem',query, data={'result': res})
		id_contest = data_problem[0]['id_contest']
		path_dir = os.path.join(TEMPLATES, str(id_contest))
		if not os.path.exists(path_dir):
			os.mkdir(path_dir)
		path_dir = os.path.join(path_dir, str(problem_name))
		if not os.path.exists(path_dir):
			os.mkdir(path_dir)
		path_dir = os.path.join(path_dir, 'result')
		if not os.path.exists(path_dir):
			os.mkdir(path_dir)
		sc.save_as_html(path_dir, and_thresholds=True)
		path_summary = path_dir.replace(TEMPLATES, '.')
		return render_template(path_summary+'/summary.html')

if __name__ == "__main__":
	app.debug = True
	app.run(host='0.0.0.0', port=5005)