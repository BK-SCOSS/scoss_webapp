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

user = Blueprint('users_page', __name__)

@user.route('/admin', methods=['GET', 'POST'])
def admin():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				url = URL + '/api/users'
				data = requests.get(url=url)
				# print(data.json())
				return render_template('admin.html', data=data.json()['users'])
			else: 
				username = request.form['username']
				password = '12345'
				role = 1
				data_form = {'username': username, 'role': role, 'password': password}
				url = URL + '/api/users/add'
				req = requests.post(url=url,json=data_form)
				if 'user_id' in req.json().keys():
					return redirect(url_for('users_page.admin'))
				else:
					return redirect(url_for('users_page.admin', info='wrong'))

@user.route('/users/<user_id>/update', methods=['POST'])
def update_password(user_id):
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'POST':
				new_pass = request.form['newpassword']
				data_form = {'password': new_pass}
				base_url = request.referrer
				url = URL + '/api/users/{}'.format(user_id)
				req = requests.put(url=url, json=data_form)
				if 'info' in req.json().keys():
					return redirect(base_url)
	else:
		return redirect(url_for('login_page.login_page'))

