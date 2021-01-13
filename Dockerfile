FROM python:3.8
 
COPY . /code

WORKDIR /code

RUN pip install rq rq-dashboard rqmonitor
RUN pip install -r requirements.txt
RUN pip install -e .

CMD ["rq", "worker"]
