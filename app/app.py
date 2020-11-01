import os
import sys
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(WORKING_DIR, '../scoss'))
from flask import Flask, render_template, url_for, request, redirect, session, jsonify, send_file
from api import scoss_api
import requests
app = Flask(__name__)

app.register_blueprint(scoss_api.mod)
@app.route('/api/login', methods=["GET"])
def login():
	return render_template('login.html')

@app.route('/api/signup', methods=["POST"])
def signup():
	pass

@app.route('/')
def index():
	return render_template('index.html')

@app.route('/document')
def document():
	return render_template('document.html')

@app.route('/api')
def api():
	return render_template('api.html')

@app.route('/test')
def test():
	return render_template('test.html')

@app.route('/contest')
def contest():
	return render_template('contest.html')

@app.route('/problem')
def problem():
	return render_template('problem.html')

@app.route('/source')
def source():
	return render_template('source.html')

@app.route('/admin')
def admin():
	return render_template('admin.html')

@app.route('/result')
def result():
	return render_template('result.html')

if __name__ == "__main__":
	app.debug = True
	app.run()