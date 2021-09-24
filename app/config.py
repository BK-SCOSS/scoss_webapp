import os

DEBUG = True
SECRET_KEY = b'_5#y2L"F4Q8z\n\xec]/'

APP_HOST = '0.0.0.0'
APP_PORT = 8080
APP_SELF_REF = '0.0.0.0'

MONGODB_HOST = 'mongodb://127.0.0.1:27017/scoss'
MONGODB_DATABASE = 'scoss'
# MONGODB_USERNAME = 'scoss_admin'
# MONGODB_PASSWORD = 'scoss_admin'

MONGO_PORT = 8081
REDIS_PORT = 8080

MONGO_EXPRESS_URL = f'http://{APP_HOST}:8081'

REDIS_MONITOR_URL = f'http://{APP_HOST}:8080/rq'

API_URI = f'http://{APP_HOST}:{APP_PORT}'
URL = f'http://{APP_HOST}:{APP_PORT}'
API_URI_SR = f'http://{APP_SELF_REF}:{APP_PORT}'
LANGUAGE_SUPPORT = ["cpp", "py", "php", "c"]
JOB_TIMEOUT = 1000

