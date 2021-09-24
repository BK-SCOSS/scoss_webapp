import os
import sys
import requests
import scoss
from werkzeug.utils import secure_filename
from flask import Flask, render_template, url_for, request, redirect, session, jsonify, Blueprint, Response, stream_with_context, flash
from sctokenizer import Source
from scoss import align_source
from scoss.metrics import all_metrics
from models.models import db, MessageStatus
from werkzeug.security import generate_password_hash, check_password_hash
from jinja2 import Environment
from config import URL

problems = Blueprint('problems_page', __name__)

@problems.route('/contests/<contest_id>/problems', methods=['GET', 'POST'])
def problem(contest_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				# error = request.args.get("error")
				url = '/api/contests/' + contest_id
				headers = {'Authorization': "Bearer {}".format(session['token'])}		
				# req = requests.get(url=url, headers=headers)
				# if req.status_code != 200 and 'msg' in req.json():
				# 	session.clear()
				# 	return redirect(url_for('login_page.login_page'))
				# elif 'error' in req.json().keys():
				# 	flash(req.json()['error'], MessageStatus.error)
				# if len(req.json()['problems']) > 0:
				# 	author = req.json()['problems'][0]['user_id']
				# 	return render_template('problem.html', data=req.json()['problems'], \
				# 		contest_id=contest_id, author=author, contest_data=req.json()['contest_data'])	
				# else:
				return render_template('problem.html', contest_id=contest_id, url=url)
			if request.method == 'POST':
				problem_name = request.form['problem_name']
				data = {'problem_name': problem_name}
				headers = {'Authorization': "Bearer {}".format(session['token'])}		
				url = URL + '/api/contests/' + contest_id +'/problems/add'
				req = requests.post(url=url, json=data, headers=headers)
				if 'error' in req.json().keys():
					flash(req.json()['error'], MessageStatus.error)
				if req.status_code != 200 and 'msg' in req.json():
					session.clear()
					return redirect(url_for('login_page.login_page'))
				if 'problem_id' in req.json().keys():
					return redirect(url_for('problems_page.problem', problem_name=problem_name, contest_id=contest_id))
				else:
					return redirect(url_for('problems_page.problem', info='wrong', contest_id=contest_id))
	return redirect(url_for('login_page.login_page'))

@problems.route('/problems/<problem_id>/sources', methods=['GET', 'POST'])
def source(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				url = '/api/problems/' + problem_id
				headers = {'Authorization': "Bearer {}".format(session['token'])}		
				# req = requests.get(url=url, headers=headers)
				# if req.status_code != 200 and 'msg' in req.json():
				# 	session.clear()
				# 	return redirect(url_for('login_page.login_page'))
				# if 'problem_id' in req.json().keys():
				return render_template('source.html', problem_id=problem_id, url=url)
			else:
				source_name = request.form['source_name']
				data_form = {'source_name': source_name}
				url = URL + '/api/problems/' + problem_id + '/sources/add'
				headers = {'Authorization': "Bearer {}".format(session['token'])}
				req = requests.post(url=url,json=data_form, headers=headers)
				if 'error' in req.json().keys():
					flash(req.json()['error'], MessageStatus.error)
				if req.status_code != 200 and 'msg' in req.json():
					session.clear()
					return redirect(url_for('login_page.login_page'))
				if 'contest_id' in req.json().keys():
					return redirect(url_for('contest_page.contest'))
				else:
					return redirect(url_for('contest_page.contest', info='wrong', error=req.json()['error']))
	return redirect(url_for('login_page.login_page'))

@problems.route('/problems/<problem_id>/add_file', methods=['POST'])
def add_file(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				mask = request.form['mask']
				sourceFile = request.files['file'].read()
				filename = request.files['file'].filename
				data_form ={'mask': mask}
				url = URL + '/api/problems/{}/sources/add'.format(problem_id)
				headers = {'Authorization': "Bearer {}".format(session['token'])}		
				req = requests.post(url=url, data=data_form, files={'files': (filename, sourceFile)}, headers=headers)
				if 'error' in req.json().keys():
					flash(req.json()['error'], MessageStatus.error)
				if req.status_code != 200 and 'msg' in req.json():
					session.clear()
					return redirect(url_for('login_page.login_page'))
				if 'problem_id' in req.json().keys():
					return redirect(url_for('problems_page.source', problem_id=problem_id))
				else:
					return redirect(url_for('problems_page.source', problem_id=problem_id))
	return redirect(url_for('login_page.login_page'))

@problems.route('/problems/<problem_id>/from_zip', methods=['POST'])
def add_zip_file(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				if request.files:
					zip_file = request.files['file'].read()					
					url = URL + '/api/problems/{}/from_zip'.format(problem_id)
					headers = {'Authorization': "Bearer {}".format(session['token'])}		
					req = requests.post(url=url, files={'file': zip_file}, headers=headers)
					if 'error' in req.json().keys():
						flash(req.json()['error'], MessageStatus.error)
					else: 
						flash("Successfully import!", MessageStatus.success)
					if req.status_code != 200 and 'msg' in req.json():
						session.clear()
						return redirect(url_for('login_page.login_page'))
					return redirect(url_for('problems_page.source', problem_id= problem_id))
				return redirect(url_for('problems_page.source', problem_id= problem_id))
	return redirect(url_for('login_page.login_page'))


@problems.route('/problems/<problem_id>/all', methods=['GET'])
def summary(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				return render_template('all.html')
	return redirect(url_for('login_page.login_page'))

def scoss_alignment(source1, source2, src_str1, src_str2, metric, score, lang):
	score_metric = round(score, 4)
	score_alignment = align_source(metric, src_str1, src_str2, lang)
	data1 = [i.replace('<', '&lt').replace('>', '&gt') for i in src_str1.split('\n')]
	data2 = [i.replace('<', '&lt').replace('>', '&gt') for i in src_str2.split('\n')]
	html1 = ''
	html2 = ''
	for line in score_alignment:
		if line[0] == -1 :
			html1 += '<pre >  </pre>'
			temp2 = '<pre >'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
			html2 += temp2
		elif line[1] == -1 :
			html2 += '<pre >  </pre>'
			temp1 = '<pre >'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
			html1 += temp1
		elif line[0] != -1 and line[0] != -1:
			if line[2] >=0.25 and line[2] <0.75:
				temp1 = '<pre style="color: #ffb600">'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
				html1 += temp1
				temp2 = '<pre style="color: #ffb600">'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
				html2 += temp2
			elif line[2] >= 0.75:
				temp1 = '<pre style="color: red">'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
				html1 += temp1
				temp2 = '<pre style="color: red">'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
				html2 += temp2
			else:
				temp1 = '<pre style="color: black">'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
				html1 += temp1
				temp2 = '<pre style="color: black">'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
				html2 += temp2
	C = int(score_metric*255)
	R = C
	G = 0
	B = 0
	span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(score_metric*100, '.2f')) +'%</span>'
	with open('app/templates/comparison.html', 'r') as f:
		HTML2 = f.read()
	return Environment().from_string(HTML2).render(file1=source1, file2=source2, \
					metric=metric, score=span, data1=html1, data2=html2)

@problems.route('/problems/<problem_id>/compare', methods=['GET'])
def compare(problem_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			source1 = request.args.get('source1')
			source2 = request.args.get('source2')
			metric = request.args.get('metric')
			headers = {'Authorization': "Bearer {}".format(session['token'])}		

			url_get_alignment = URL + '/api/problems/{}/get_alignment'.format(problem_id)
			result = requests.post(url=url_get_alignment, json={'source1':source1, 'source2':source2}, headers=headers).json()
			
			if metric == 'moss_score':
				return result['result'][0]['smoss_alignment']
			
			url_get_problem = URL + '/api/problems/{}'.format(problem_id)
			problem = requests.get(url=url_get_problem, headers=headers).json()
			sources = problem['sources']
			source1_dict = {}
			source2_dict = {}
			for src in sources:
				if src['mask'] == source1:
					source1_dict = src
				if src['mask'] == source2:
					source2_dict = src
				if source1_dict and source2_dict:
					break

			score = result['result'][0]['scores'][metric]
			return scoss_alignment(source1, source2, source1_dict['source_str'], source2_dict['source_str'], metric, score, source1_dict['lang'])
	return redirect(url_for('login_page.login_page'))