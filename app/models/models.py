from __future__ import absolute_import
from flask_mongoengine import MongoEngine
db = MongoEngine()

class User(db.Document):
    user_id = db.StringField(required=True, unique=True)
    username = db.StringField()
    password = db.StringField()
    role = db.IntField()

class Contest(db.Document):
    contest_id = db.StringField(required=True, unique=True)
    contest_name = db.StringField()
    metrics = db.ListField()
    user_id = db.StringField()
    contest_status = db.StringField()
    
class Problem(db.Document):
    problem_id = db.StringField(required=True, unique=True)
    problem_name = db.StringField()
    sources = db.ListField()
    metrics = db.ListField()
    similarity_list = db.ListField()
    aligment_list = db.ListField()
    similarity_smoss_list = db.ListField()
    aligment_smoss_list = db.ListField()
    contest_id = db.StringField()
    user_id = db.StringField()

