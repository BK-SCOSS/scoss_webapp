from threading import Thread
import threading
import time

from redis import Redis
from rq import Queue

r = Redis(host='rq-server', port=6379)
tq = Queue(connection=r)

