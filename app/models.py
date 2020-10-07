from __future__ import absolute_import
from app import db

class User(db.Document):
    user_id = db.StringField(required=True, unique=True)
    username = db.StringField(required=True, unique=True)
    password = db.StringField()

class ScossDb(db.Document):
    scoss_id = db.StringField(required=True, unique=True)
    scoss_name = db.StringField(required=True)
  

class Problem(db.Document):
    problem_id = db.StringField(required=True, unique=True)
    scoss_id = db.StringField()
    sources = db.DictField()
    metrics = db.ListField()
    similarity_matrix = db.ListField()
    aligment_matrix = db.ListField()