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

home = Blueprint('home_page', __name__)

@home.route('/')
def index():
	return render_template('index.html')

@home.route('/document')
def document():
	if 'logged_in' in session:
		return render_template('document.html')
	else:
		return redirect(url_for('login_page.login_page'))

@home.route('/api')
def api():
	return render_template('api.html')