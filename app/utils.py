import yaml
import os
from yaml import Loader
from uuid import uuid4
def load_config(filepath='./config/config.yml'):
    config = yaml.load(open(filepath, mode='r'), Loader=Loader)
    return config

def make_unique(string):
    ident = uuid4().__str__()[:8]
    return f"{ident}-{string}"