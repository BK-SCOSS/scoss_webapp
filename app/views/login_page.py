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
		params = {'username': username}
		url = URL + '/api/user'
		req = requests.get(url=url, params=params)
		print( check_password_hash(req.json()['password'], password))
		if 'password' in req.json().keys():
			if check_password_hash(req.json()['password'], password):
				session['username'] = username
				session['logged_in'] = True
				return redirect(url_for('home_page.index'))
			else:
				return render_template('login.html', info='wrong_pass')
		return render_template('login.html', info='wrong_user')
@login.route('/logout')
def logout():
	session.clear()
	return render_template('login.html', info='')

@login.route('/signup', methods=["GET", "POST"])
def signup():
	if request.method == "GET":
		return render_template('register.html')
	else:
		username = request.form['username']
		password = request.form['password']
		level = request.form['level']
		data = {'username': username , 'password': generate_password_hash(password), 'level':level}
		url = URL +'/api/user'
		req = requests.post(url=url, data=data)
		if 'user_id' not in req.json().keys():
			return jsonify({'info': 'False'})
		return jsonify({'info': 'True'})
		
