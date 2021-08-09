FROM python:3.8
 
COPY . /code

WORKDIR /code

RUN pip install -r requirements.txt

CMD ["rq", "worker"]
