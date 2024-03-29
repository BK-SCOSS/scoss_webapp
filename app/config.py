import os
from dotenv import load_dotenv
load_dotenv()

DEBUG = True
SECRET_KEY = str.encode(os.getenv('SECRET_KEY'))

APP_HOST = '0.0.0.0'
APP_PORT = 8080
APP_SELF_REF = 'scoss_app'

MONGODB_HOST = 'mongodb://mongo:27017/scoss'
MONGODB_DATABASE = 'scoss'
MONGODB_USERNAME = os.getenv('MONGODB_USER')
MONGODB_PASSWORD = os.getenv('MONGODB_PASS')

MONGO_PORT = 8081
REDIS_PORT = 8080

MONGO_EXPRESS_URL = f'http://{APP_HOST}:{MONGO_PORT}'

REDIS_MONITOR_URL = f'http://{APP_HOST}:{REDIS_PORT}/rq'
REDIS_SERVER_PASS=os.getenv('REDIS_SERVER_PASS')

RQ_DASHBOARD_LOGIN = os.getenv('RQ_DASHBOARD_LOGIN')
RQ_DASHBOARD_PASS = os.getenv('RQ_DASHBOARD_PASS')

API_URI = f'http://{APP_HOST}:{APP_PORT}'
URL = f'http://{APP_HOST}:{APP_PORT}'
API_URI_SR = f'http://{APP_SELF_REF}:{APP_PORT}'

JOB_TIMEOUT = 1000

SUPPORTED_EXTENSIONS = ('.c', '.cc', '.cpp', '.py', '.java', '.php')

server_name = None