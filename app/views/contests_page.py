import os
import sys
from werkzeug.utils import secure_filename
from flask import Flask, render_template, url_for, request, redirect, session, jsonify, Blueprint, flash
from scoss import smoss
import requests
from sctokenizer import Source
from scoss import Scoss
from scoss.metrics import all_metrics
from models.models import db, MessageStatus
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
				headers = {'Authorization': "Bearer {}".format(session['token'])}
				if int(role) == 0:
					url = '/api/contests'
					# data = requests.get(url=url, headers=headers)
				else:	
					url = '/api/users/' + user_id + '/contests'
					# data = requests.get(url=url, headers=headers)
				# if data.status_code != 200 and 'msg' in data.json():
				# 	session.clear()
				# 	return redirect(url_for('login_page.login_page'))
				return render_template('contest.html', url=url, headers=headers)
			else: 
				# print(request.form['contest_name'])
				user_id = session['user_id']
				contest_name = request.form['contest_name']
				headers = {"Authorization": "Bearer {}".format(session['token'])}
				data_form = {'contest_name': contest_name}
				url = URL + '/api/users/' + user_id + '/contests/add'
				req = requests.post(url=url,json=data_form, headers=headers)
				if req.status_code != 200 and 'msg' in req.json():
					session.clear()
					return redirect(url_for('login_page.login_page'))
				if 'error' in req.json().keys():
					flash(req.json()['error'], MessageStatus.error)
				return redirect(url_for('contest_page.contest'))
				
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
					headers = {'Authorization': "Bearer {}".format(session['token'])}			
					url = URL + '/api/contests/{}/from_zip'.format(contest_id)
					req = requests.post(url=url, files={'file': zip_file}, headers=headers)
					if req.status_code != 200 and 'msg' in req.json():
						session.clear()
						return redirect(url_for('login_page.login_page'))
					if 'error' in req.json().keys():
						flash(req.json()['error'], MessageStatus.error)
					else: 
						flash("Successfully import!", MessageStatus.success)
					return redirect(url_for('problems_page.problem', contest_id= contest_id))
				return redirect(url_for('problems_page.problem', contest_id= contest_id))
	return redirect(url_for('login_page.login_page'))

@contests.route('/contests/<contest_id>/results', methods=['GET'])
def results(contest_id):
	if request.method == 'GET':
		return render_template('result.html', contest_id=contest_id)
	return redirect(url_for('login_page.login_page'))