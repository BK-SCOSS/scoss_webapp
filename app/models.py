from __future__ import absolute_import
from app import db

class User(db.Document):
    user_id = db.StringField(required=True, unique=True)
    username = db.StringField(required=True, unique=True)
    password = db.StringField()
    level = db.IntField()

class Contest(db.Document):
    contest_name = db.StringField()
    contest_author = db.StringField()
  
class Problem(db.Document):
    problem_name = db.StringField()
    contest_name = db.StringField()
    sources = db.ListField()
    metrics = db.ListField()
    similarity_matrix = db.ListField()
    aligment_matrix = db.ListField()
    similarity_matrix_smoss = db.ListField()
    aligment_matrix_smoss = db.ListField()

