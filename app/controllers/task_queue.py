from threading import Thread
import threading
import time

from redis import Redis
from rq import Queue

# r = Redis(host='rq-server', port=6379)
r = Redis(host='rq-server', port=6379, password='redis_server_pass', charset='utf-8')
tq = Queue(connection=r)

