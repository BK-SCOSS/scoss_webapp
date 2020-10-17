from queue import Queue, Full
from threading import Thread
import threading
import time
from .similarity_checker import run_problem
class TaskQueue():
    def __init__(self, do_work, num_workers=4, queue_size=10000):
        self.__queue = Queue(queue_size)
        self.__workers = []
        self.__num_workers = num_workers
        self.__do_work = do_work
        for _ in range(self.__num_workers):
            thread = Thread(target=self.__run_worker)
            thread.daemon = True
            thread.start()
            self.__workers.append(thread)

    def get_num_workers(self):
        return self.__num_workers

    def set_num_workers(self, num_workers):
        self.__num_workers = num_workers

    def get_do_work(self):
        return self.__do_work

    def set_do_work(self, do_work):
        self.__do_work = do_work

    def __run_worker(self):
        while True:
            data = self.__queue.get()
            self.__do_work(data)
            self.__queue.task_done()

    def enqueue(self, data, timeout=None):
        self.__queue.put(data, timeout=timeout)

    def enqueue_nowait(self, data):
        try:
            self.__queue.put_nowait(data)
            return True
        except Full:
            return False

    def join(self):
        """join.
            Wait until all job are done
        """
        self.__queue.join()

tq = TaskQueue(do_work=run_problem, num_workers=4, queue_size=100000)