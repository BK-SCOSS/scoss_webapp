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

login = Blueprint('login_page', __name__)

@login.route('/login', methods=["GET", "POST"])
def login_page():
	if request.method == "GET":
		return render_template('login.html')
	else:
		session['logged_in'] = False 
		username = request.form['username']
		password = request.form['password']
		url = URL + '/api/login'
		payload = {"username": username, "password": password}
		req = requests.post(url=url, json=payload)
		if req.status_code == 200:
			session['user_id'] = req.json()['user_id']
			session['username'] = req.json()['username']
			session['role'] = req.json()['role']
			session['token'] = req.json()['token']
			session['logged_in'] = True
			return redirect(url_for('home_page.index'))
		return render_template('login.html', info='wrong_pass')

@login.route('/logout')
def logout():
	url = "{}/api/logout".format(URL)
	token = session['token']
	headers = {'Authorization': "Bearer {}".format(token)}
	requests.get(url, headers=headers)
	session.clear()
	return redirect(url_for('home_page.index'))


@login.route('/signup', methods=["GET", "POST"])
def signup():
	if request.method == "GET":
		return render_template('register.html')
	else:
		username = request.form['username']
		password = request.form['password']
		level = request.form['level']
		data = {'username': username , 'password': generate_password_hash(password), 'role':level}
		url = URL +'/api/users/add'
		req = requests.post(url=url, data=data)
		if 'user_id' not in req.json().keys():
			return jsonify({'info': 'False'})
		return jsonify({'info': 'True'})
		
