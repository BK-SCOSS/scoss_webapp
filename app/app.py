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
	pass
@app.route('/api/signup', methods=["POST"])
def signup():
	pass
@app.route('/')
def index():
	pass

if __name__ == "__main__":
	app.debug = True
	app.run(host='0.0.0.0', port=5005)