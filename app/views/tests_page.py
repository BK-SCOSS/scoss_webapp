import os
import sys
from werkzeug.utils import secure_filename
from flask import Flask, render_template, url_for, request, redirect, session, jsonify, Blueprint
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

tests = Blueprint('tests_page', __name__)

@tests.route('/test', methods=['GET', 'POST'])
def test():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				if 'sources' in session:
					return render_template('test.html', data=session['sources'])
				else:
					session['sources'] = []
					return render_template('test.html')
			else:
				mask = request.form['mask']
				sourceFile = request.files['file']
				data_doc = {
					"pathfile": sourceFile.filename,
					"lang": sourceFile.filename.split('.')[-1],
					'mask': mask,
					'source_str': sourceFile.read().decode('utf-8')
				}
				if 'sources' in session:
					temp = session['sources']
					temp.append(data_doc)
					session['sources'] = temp

				return redirect(url_for('tests_page.test'))
	return redirect(url_for('login'))

@tests.route('/test/from_zip', methods=['POST'])
def from_zip():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				if request.files:
					sourceFile = request.files['zipfile']
					sources = []
					with ZipFile(sourceFile, 'r') as zf:
						zfile = zf.namelist()
						for file in zfile:
							if len(file.split('/')) > 1 and file.split('/')[-1] != '':
								data_doc = {
									"pathfile": file.split('/')[-1],
									"lang": file.split('.')[-1],
									'mask': '',
									'source_str': zf.read(file).decode('utf-8')
								}
								sources.append(data_doc)

					if 'sources' in session:
						temp = session['sources']
						fin = temp + sources 
						session['sources'] = fin

					return redirect(url_for('tests_page.test'))
	return redirect(url_for('login_page.login_page'))

@tests.route('/test/run', methods=['POST'])
def run():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				sources = session['sources']
				list_operator = request.form
				metrics = []
				metric_list = []

				print(sources)

				for op in list_operator:
					temp = {
						'name': op,
						'threshold': float(int(list_operator[op])/100)
					}
					metrics.append(temp)
					metric_list.append(op)

				print(metrics)

				for metric in all_metrics:
					for met in metrics:
						if metric.get_name() == met['name']:
							similarity_list, alignment_list = cal_scoss(sources, metrics)
							break
				for met in metrics:
					if met['name'] == 'moss_score':
						similarity_smoss_list, alignment_smoss_list = cal_smoss(sources, metrics)
						break
				
				if len(similarity_list) >= 0 and len(similarity_smoss_list) >= 0:
					results = get_results(similarity_list, similarity_smoss_list, metrics)
				else:
					results = []

				if len(results) > 0:
					heads = []
					heads.append('source1')
					heads.append('source2')
					for metric in results[0]['results'][0]['scores']:
						if (metric == 'mean'):
							continue
						heads.append(metric)
					heads.append('mean')

					for problem in results:
						for prob_res in problem['results']:
							for metric in prob_res['scores']:
								score_metric = prob_res['scores'][metric]
								score_metric = round(score_metric, 4)
								C = int(score_metric*255)
								R = C
								G = 0
								B = 0
								span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(score_metric*100, '.2f')) +'%</span>'								
								prob_res['scores'][metric] = span

					return render_template('result.html', heads=heads, data=results)
				else:
					return render_template('result.html', error="No result in database!")
	return redirect(url_for('login_page.login_page'))

def get_results(similarity_list, similarity_smoss_list, metrics):
	metric_list = []
	res = {}
	for metric in metrics:
		metric_list.append(metric['name'])
	if 'moss_score' in metric_list:
		if len(metric_list) == 1:
			for simi in similarity_list:             
				key = hash(simi['source1'])^hash(simi['source2'])
				temp_list = simi 
				res[key] = temp_list
		else: 
			for simi in similarity_list:             
				key = hash(simi['source1'])^hash(simi['source2'])
				temp_list = simi 
				temp_list['scores']['moss_score'] =  0
				res[key] = temp_list
			for simi_smoss in similarity_smoss_list:        
				key = hash(simi_smoss['source1'])^hash(simi_smoss['source2'])
				if key in res.keys():
					temp_list = simi_smoss
					for metric in metric_list:
						temp_list['scores'][metric] =  0
					temp_list['scores']['moss_score'] =  simi_smoss['scores']['moss_score']
					res[key] = temp_list
			for simi in similarity_list:
				for simi_smoss in similarity_smoss_list:
					if (simi['source1'] == simi_smoss['source1'] and simi['source2'] == simi_smoss['source2'])\
						or (simi['source1'] == simi_smoss['source1'] and simi['source2'] == simi_smoss['source2']):
						key = hash(simi['source1'])^hash(simi['source2'])
						temp_list = simi 
						temp_list['scores']['moss_score'] =  simi_smoss['scores']['moss_score']
						res[key] = temp_list
	else:
		for simi in similarity_list:             
			key = hash(simi['source1'])^hash(simi['source2'])
			temp_list = simi 
			res[key] = temp_list
	check_zero = 0
	for key in res:
		total = 0
		num_of_score = 0
		if len(res[key]) == 0:
			check_zero+=1
			continue
		for score in res[key]['scores']:
			total += res[key]['scores'][score]
			num_of_score +=1
		if num_of_score != 0:
			res[key]['scores']['mean'] = total/num_of_score
	if(len(res.keys()) == check_zero):
			return []
	return list(res.values())