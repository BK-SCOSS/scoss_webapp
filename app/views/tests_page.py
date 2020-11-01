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

tests = Blueprint('tests_page', __name__)

@tests.route('/test')
def test():
	if 'logged_in' in session:
		if session['logged_in'] == True:
			if request.method == 'GET':
				req = requests.get(url=url)
				return render_template('test.html')
			else:
				source_name = request.form['source_name']
				data_form = {'source_name': source_name}
				url = URL + '/api/problems/' + problem_id + '/sources/add'
				req = requests.post(url=url,json=data_form)
				return redirect(url_for('tests_page.test'))
	return redirect(url_for('login'))
