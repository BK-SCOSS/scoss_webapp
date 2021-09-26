from threading import Thread
import threading
import time

from redis import Redis
from rq import Queue
from config import REDIS_SERVER_PASS

r = Redis(host='rq-server', port=6379, password=REDIS_SERVER_PASS, charset='utf-8')
tq = Queue(connection=r)