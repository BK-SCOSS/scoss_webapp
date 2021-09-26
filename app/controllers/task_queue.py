from threading import Thread
import threading
import time

from redis import Redis
from rq import Queue
from config import REDIS_SERVER_PASS

r = Redis(host='localhost', port=6379, charset='utf-8')
tq = Queue(connection=r)

