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

contests = Blueprint('contest_page', __name__)


@contests.route('/contest', methods=['GET', 'POST'])
def contest():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				user_id = session['user_id']
				role = session['role']
				if int(role) == 0:
					url = URL + '/api/contests'
					data = requests.get(url=url)
				else:	
					url = URL + '/api/users/' + user_id + '/contests'
					data = requests.get(url=url)
				# print(data.json())
				return render_template('contest.html', data=data.json()['contests'])
			else: 
				# print(request.form['contest_name'])
				user_id = session['user_id']
				contest_name = request.form['contest_name']
				data_form = {'contest_name': contest_name}
				url = URL + '/api/users/' + user_id + '/contests/add'
				req = requests.post(url=url,json=data_form)
				if 'contest_id' in req.json().keys():
					return redirect(url_for('contest_page.contest'))
				else:
					return redirect(url_for('contest_page.contest', info='wrong', error=req.json()['error']))
		else:
			return redirect(url_for('login_page.login_page'))
	else:
		return redirect(url_for('login_page.login_page'))

@contests.route('/contests/<contest_id>/from_zip', methods=['POST'])
def add_zip_file(contest_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				if request.files:
					zip_file = request.files['file'].read()					
					url = URL + '/api/contests/{}/from_zip'.format(contest_id)
					req = requests.post(url=url, files={'file': zip_file})
					return redirect(url_for('problems_page.problem', contest_id= contest_id))
				return redirect(url_for('problems_page.problem', contest_id= contest_id))
	return redirect(url_for('login'))

@contests.route('/contests/<contest_id>/run', methods=['POST'])
def run(contest_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				check_status_url = URL + '/api/contests/check_status'
				check_status_req = requests.get(url=check_status_url)

				list_operator = request.form
				send_data = []
				for op in list_operator:
					temp = {
						'name': op,
						'threshold': float(int(list_operator[op])/100)
					}
					send_data.append(temp)
				data_form = {'metrics': send_data}
				url = URL + '/api/contests/{}/run'.format(contest_id)
				req = requests.post(url=url, json=data_form)
				if 'contest_id' in req.json().keys():	
					return redirect(url_for('problems_page.problem', contest_id=contest_id))
				return redirect(url_for('problems_page.problem', contest_id=contest_id))
	return redirect(url_for('login'))