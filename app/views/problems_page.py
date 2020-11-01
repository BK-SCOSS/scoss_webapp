import os
import sys
from werkzeug.utils import secure_filename
from flask import Flask, render_template, url_for, request, redirect, session, jsonify, Blueprint
import requests
from sctokenizer import Source
from scoss import Scoss
from scoss.metrics import all_metrics
from models.models import db
from werkzeug.security import generate_password_hash, check_password_hash
from jinja2 import Environment
from config import URL

problems = Blueprint('problems_page', __name__)




@problems.route('/contests/<contest_id>/problems', methods=['GET', 'POST'])
def problem(contest_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				url = URL + '/api/contests/' + contest_id
				req = requests.get(url=url)
				if 'contest_id' in req.json().keys():
					if len(req.json()['problems']) > 0:
						author = req.json()['problems'][0]['user_id']
						return render_template('problem.html', data=req.json()['problems'], contest_id=contest_id, author=author)	
					else:
						return render_template('problem.html', contest_id=contest_id)
				else:
					return render_template('problem.html', contest_id=contest_id, error=req.json()['error'])
			if request.method == 'POST':
				problem_name = request.form['problem_name']
				data = {'problem_name': problem_name}
				url = URL + '/api/contests/' + contest_id +'/problems/add'
				req = requests.post(url=url, json=data)
				if 'problem_id' in req.json().keys():
					return redirect(url_for('problems_page.problem', problem_name=problem_name, contest_id=contest_id))
				else:
					return redirect(url_for('problems_page.problem', info='wrong', contest_id=contest_id))
	return redirect(url_for('login'))

@problems.route('/problems/<problem_id>/sources', methods=['GET', 'POST'])
def source(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				url = URL + '/api/problems/' + problem_id
				req = requests.get(url=url)
				if 'problem_id' in req.json().keys():
					return render_template('source.html', data=req.json()['sources'], 
						problem_name=req.json()['problem_name'], problem_id=req.json()['problem_id'])
			else:
				source_name = request.form['source_name']
				data_form = {'source_name': source_name}
				url = URL + '/api/problems/' + problem_id + '/sources/add'
				req = requests.post(url=url,json=data_form)
				if 'contest_id' in req.json().keys():
					return redirect(url_for('contest_page.contest'))
				else:
					return redirect(url_for('contest_page.contest', info='wrong', error=req.json()['error']))
	return redirect(url_for('login'))

@problems.route('/problems/<problem_id>/add_file', methods=['POST'])
def add_file(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				mask = request.form['mask']
				sourceFile = request.files['file'].read()
				data_form ={'mask': mask}
				url = URL + '/api/problems/{}/sources/add'.format(problem_id)
				req = requests.post(url=url, data=data_form, files={'files': sourceFile})
				if 'problem_id' in req.json().keys():
					return redirect(url_for('problems_page.source', problem_id=problem_id))
				else:
					return redirect(url_for('problems_page.source', problem_id=problem_id))
	return redirect(url_for('login_page.login_page'))

@problems.route('/problems/<problem_id>/run', methods=['POST'])
def run(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				list_operator = request.form
				send_data = []
				for op in list_operator:
					temp = {
						'name': op,
						'threshold': float(int(list_operator[op])/100)
					}
					send_data.append(temp)
				data_form = {'metrics': send_data}
				url = URL + '/api/problems/{}/run'.format(problem_id)
				req = requests.post(url=url, json=data_form)
				if 'problem_id' in req.json().keys():	
					return redirect(url_for('problems_page.result', problem_id=problem_id))
						# return render_template('result.html', links=result.json()['results'])
					# else:
					# 	return redirect(url_for('problems_page.source', problem_id=problem_id, error=result.json()['error']))
				else:
					return redirect(url_for('problems_page.source', problem_id=problem_id, error=req.json()['error']))
	# else:
	# 	return redirect(url_for('login_page.logout'))

@problems.route('/problems/<problem_id>/result')
def result(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				url = URL + '/api/problems/{}/results'.format(problem_id)
				result = requests.get(url=url)
				data = result.json()
				tdata = [item for sublist in data['results'] for item in sublist]
				print(tdata)
				if len(tdata) > 0:
					heads = []
					heads.append('source1')
					heads.append('source2')
					for metric in tdata[0]['scores']:
						heads.append(metric)

					url = URL + '/api/problems/' + problem_id
					req = requests.get(url=url)
					if 'problem_id' in req.json().keys():
						return render_template('source.html', data=req.json()['sources'],
							problem_name=req.json()['problem_name'], problem_id=req.json()['problem_id'],
							heads=heads, links=tdata)
				else:
					return render_template('result.html', error="No source in database")
				if len(data['similarity_matrix']) > 0:
					links = []
					for matrix in data['similarity_matrix']:
						dic = {}
						dic['source1'] = matrix['source1']
						dic['source2'] = matrix['source2']
						dic['scores'] = {}
						for metric, score in matrix['scores'].items():			
							C = int(score)*255
							R = C
							G = 0
							B = 0
							span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(score*100, '.2f')) +'%</span>'
							dic['scores'][metric] = span
						if len(data['similarity_matrix_smoss']) > 0:
							for data_smoss in data['similarity_matrix_smoss']:
								if data_smoss['source1'] == matrix['source1'] and data_smoss['source2'] == matrix['source2']:
									C = int(data_smoss['scores']['moss_score'])*255
									R = C
									G = 0
									B = 0
									span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(data_smoss['scores']['moss_score']*100, '.2f')) +'%</span>'
									dic['scores']['smoss_metric'] = span
								elif data_smoss['source1'] == matrix['source2'] and data_smoss['source2'] == matrix['source1']:
									C = int(data_smoss['scores']['moss_score'])*255
									R = C
									G = 0
									B = 0
									span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(data_smoss['scores']['moss_score']*100, '.2f')) +'%</span>'
									dic['scores']['smoss_metric'] = span
						links.append(dic)
				else:
					links = []
					for matrix in data['similarity_matrix_smoss']:
						dic = {}
						dic['source1'] = matrix['source1']
						dic['source2'] = matrix['source2']
						dic['scores'] = {}
						for metric, score in matrix['scores'].items():			
							C = int(score)*255
							R = C
							G = 0
							B = 0
							span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(score*100, '.2f')) +'%</span>'
							dic['scores']['smoss_metric'] = span
						links.append(dic)
	return redirect(url_for('login'))

@problems.route('/problems/<problem_id>/from_zip', methods=['POST'])
def add_zip_file(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				if request.files:
					zip_file = request.files['file'].read()					
					url = URL + '/api/problems/{}/from_zip'.format(problem_id)
					req = requests.post(url=url, files={'file': zip_file})
					return redirect(url_for('problems_page.source', problem_id= problem_id))
				return redirect(url_for('problems_page.source', problem_id= problem_id))
	return redirect(url_for('login'))


@problems.route('/problems/<problem_id>/all', methods=['GET'])
def summary(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				return render_template('all.html')
	return redirect(url_for('login_page.login_page'))