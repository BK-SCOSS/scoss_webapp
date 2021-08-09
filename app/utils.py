import yaml
import os
from yaml import Loader

def load_config(filepath='./config/config.yml'):
    config = yaml.load(open(filepath, mode='r'), Loader=Loader)
    return config
