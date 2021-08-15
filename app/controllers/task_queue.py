from threading import Thread
import threading
import time

from redis import Redis
from rq import Queue

# r = Redis(host='rq-server', port=6379)
r = Redis(host='127.0.0.1', port=6379, charset='utf-8')
tq = Queue(connection=r)

