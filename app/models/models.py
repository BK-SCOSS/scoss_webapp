from __future__ import absolute_import
from flask_mongoengine import MongoEngine
import datetime
from flask_jwt_extended import verify_jwt_in_request, get_jwt
from flask import jsonify
from functools import wraps
db = MongoEngine()


class Status():
    init = 1
    failed = 2
    waiting = 3
    running = 4
    checked = 5

class MessageStatus():
    error = 'danger'
    success = 'success'
    warning = 'warning'

class User(db.Document):
    user_id = db.StringField(required=True, unique=True)
    username = db.StringField(required=True, unique=True)
    password = db.StringField()
    email = db.StringField()
    public_token = db.StringField()
    role = db.IntField() # 0- admin, 1-user

class Contest(db.Document):
    contest_id = db.StringField(required=True, unique=True)
    contest_name = db.StringField()
    metrics = db.ListField()
    user_id = db.StringField(required=True)
    contest_status = db.IntField(required=True)
    created_at = db.DateTimeField(required=True, default=datetime.datetime.utcnow)
    
class Problem(db.Document):
    problem_id = db.StringField(required=True, unique=True)
    problem_name = db.StringField(required=True)
    problem_status = db.IntField(required=True)
    sources = db.ListField()
    metrics = db.ListField()
    contest_id = db.StringField()
    user_id = db.StringField()
    log = db.StringField()

class Result(db.Document):
    result_id = db.StringField(required=True, unique=True)
    problem_id = db.StringField(required=True)
    problem_name = db.StringField(required=True)
    source1 = db.StringField(required=True)
    source2 = db.StringField(required=True)
    scores = db.DictField()
    smoss_alignment = db.StringField()

class Project(db.Document):
    project_id = db.StringField(required=True, unique=True)
    project_name = db.StringField(required=True)
    public_token = db.StringField(required=True)
    project_status = db.IntField(required=True)
    sources = db.ListField()
    metrics = db.ListField()
    log = db.StringField()

class Counter(db.Document):
    name = db.StringField()
    count_user = db.IntField()
    count_problem = db.IntField()
    count_contest = db.IntField()

class TokenBlocklist(db.Document):
    jti = db.StringField()
    created_at = db.DateTimeField()

def admin_required(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        verify_jwt_in_request()
        claims = get_jwt()
        if int(claims['sub']['role']) != 0:
            return jsonify(error='request admin role permission'), 403
        else:
            return fn(*args, **kwargs)
    return wrapper
