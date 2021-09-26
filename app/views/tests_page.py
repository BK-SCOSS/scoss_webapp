import os
import sys
from werkzeug.utils import secure_filename
from flask import Flask, render_template, url_for, request, redirect, session, jsonify, Blueprint, flash
from scoss import smoss
import requests
from sctokenizer import Source
from scoss import Scoss
from scoss.metrics import all_metrics
from models.models import db
from werkzeug.security import generate_password_hash, check_password_hash
from jinja2 import Environment
from config import URL
from zipfile import ZipFile
from controllers.similarity_checker import cal_smoss, cal_scoss
from scoss import align_source
from models.models import db, MessageStatus

tests = Blueprint('tests_page', __name__)


@tests.route('/test', methods=['GET'])
def source():
	if request.method == 'GET':
		project_id =  request.args.get("project_id")
		url = '/api/project/test_scoss'
		if project_id == "test_scoss":
			return render_template('test.html', project_id= "test_scoss", url=url)
	return render_template('test.html')



@tests.route('/project/<project_id>/from_zip', methods=['POST'])
def add_zip_file(project_id):
	if request.method == 'POST':
		if request.files:
			zip_file = request.files['file'].read()					
			url = URL + '/api/project/{}/from_zip'.format(project_id)	
			req = requests.post(url=url, files={'file': zip_file})
			if 'error' in req.json().keys():
				flash(req.json()['error'], MessageStatus.error)
				return redirect(url_for('tests_page.source'))
			else: 
				flash("Successfully import!", MessageStatus.success)
			return redirect(url_for('tests_page.source', project_id= "test_scoss"))
		return redirect(url_for('tests_page.source'))
	return redirect(url_for('login_page.login_page'))

@tests.route('/project/<project_id>/results', methods=['GET'])
def results(project_id):
	if request.method == 'GET':
		return render_template('public_api_result.html', project_id=project_id)
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

@tests.route('/project/<project_id>/compare', methods=['GET'])
def compare(project_id):
	source1 = request.args.get('source1')
	source2 = request.args.get('source2')
	metric = request.args.get('metric')
	url_get_alignment = URL + '/api/project/{}/get_alignment'.format(project_id)
	result = requests.post(url=url_get_alignment, json={'source1':source1, 'source2':source2}).json()
	
	if metric == 'moss_score':
		return result['result'][0]['smoss_alignment']
	
	url_get_project = URL + '/api/project/{}'.format(project_id)
	project = requests.get(url=url_get_project).json()
	sources = project['sources']
	source1_dict = {}
	source2_dict = {}
	for src in sources:
		if src['mask'] == source1 or src['pathfile'] == source1:
			source1_dict = src
		if src['mask'] == source2 or src['pathfile'] == source2:
			source2_dict = src
		if source1_dict and source2_dict:
			break

	score = result['result'][0]['scores'][metric]
	return scoss_alignment(source1, source2, source1_dict['source_str'], source2_dict['source_str'], metric, score, source1_dict['lang'])