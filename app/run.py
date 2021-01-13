import os
import sys
import argparse
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(WORKING_DIR, './'))
from flask import Flask, render_template, url_for, request, redirect, session, jsonify
from models.models import db
import config

# config 
app = Flask(__name__)
app.config.from_object('config')
db.init_app(app)

#import controller
#import views
from controllers.contests_controller import contests_controller
from controllers.problems_controller import problems_controller
from controllers.users_controller import users_controller
from controllers.task_queue import tq

from views.contests_page import contests
from views.home_page import home
from views.users_page import user
from views.login_page import login
from views.problems_page import problems
from views.tests_page import tests
# from view.
app.register_blueprint(contests_controller)
app.register_blueprint(problems_controller)
app.register_blueprint(users_controller)
app.register_blueprint(contests)
app.register_blueprint(home)
app.register_blueprint(user)
app.register_blueprint(login)
app.register_blueprint(problems)
app.register_blueprint(tests)



if __name__ == "__main__":
	app.debug = True
	app.run(host=config.APP_HOST, port=config.APP_PORT)


