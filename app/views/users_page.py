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
import config
user = Blueprint('users_page', __name__)

@user.route('/admin', methods=['GET', 'POST'])
def admin():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if session['role'] == 0:
				if request.method == 'GET':
					url = URL + '/api/users'
					headers = {'Authorization': "Bearer {}".format(session['token'])}		
					data = requests.get(url=url, headers=headers)
					# print(data.json())
					if data.status_code != 200 and 'msg' in data.json():
						session.clear()
						return redirect(url_for('login_page.login_page'))
					return render_template('admin.html', data=data.json()['users'])
				else: 
					username = request.form['username']
					password = '12345'
					role = 1
					data_form = {'username': username, 'role': role, 'password': password}
					url = URL + '/api/users/add'
					headers = {'Authorization': "Bearer {}".format(session['token'])}	
					req = requests.post(url=url,json=data_form, headers=headers)
					if req.status_code != 200 and 'msg' in req.json():
						session.clear()
						return redirect(url_for('login_page.login_page'))
					if 'user_id' in req.json().keys():
						return redirect(url_for('users_page.admin'))
					else:
						return redirect(url_for('users_page.admin', info='wrong'))

@user.route('/admin/redis', methods=['GET'])
def admin_rq():
	server_name = request.host.split(":")[0]
	url = 'http://{}:{}/rq'.format(server_name, config.REDIS_PORT)
	return redirect(url)

@user.route('/admin/mongo', methods=['GET'])
def admin_mg():
	server_name = request.host.split(":")[0]
	# print("server_name " + server_name, flush=True)
	url = 'http://{}:{}'.format(server_name, config.MONGO_PORT)
	return redirect(url)

@user.route('/users/<user_id>/update', methods=['POST'])
def update_password(user_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				old_pass = request.form['old_password']
				new_pass = request.form['new_password']
				data_form = {
					'old_password': old_pass,
					'new_password': new_pass
				}
				base_url = request.referrer
				url = URL + '/api/users/{}'.format(user_id)
				headers = {'Authorization': "Bearer {}".format(session['token'])}	
				req = requests.put(url=url, json=data_form, headers=headers)
				if req.status_code != 200 and 'msg' in req.json():
					session.clear()
					return redirect(url_for('login_page.login_page'))
				if 'info' in req.json().keys():
					return redirect(base_url)
	else:
		return redirect(url_for('login_page.login_page'))

