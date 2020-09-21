from __future__ import absolute_import

import os

def get_filename(filepath):
    return os.path.basename(filepath)

def get_basename(filepath):
    filename = get_filename(filepath)
    return os.path.splitext(filename)[0]
    
