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

admin = Blueprint('admin_page', __name__)

@admin.route('/admin', methods=['GET', 'POST'])
def list_user():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				url = URL + '/api/users'
				data = requests.get(url=url)
				# print(data.json())
				return render_template('admin.html', data=data.json()['data'])
			# else: 
			# 	print(request.form)
			# 	contest_name = request.form['contest_name']
			# 	data_form = {'contest_name': contest_name, 'contest_author': session['user_id']}
			# 	url = URL + '/api/contests/add'
			# 	req = requests.post(url=url,data=data_form)
			# 	if 'contest_name' in req.json().keys():
			# 		return redirect(url_for('contest_page.contest'))
			# 	else:
			# 		return redirect(url_for('contest_page.contest', info='wrong'))