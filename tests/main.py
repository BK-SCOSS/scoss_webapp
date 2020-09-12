import os
import sys
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(WORKING_DIR, '../scoss'))
from scoss import Scoss
from sctokenizer import Source

# src1 = Source.from_file('tests/data/a.cpp', lang='cpp')
# src2 = Source.from_file('tests/data/b.cpp', lang='cpp')

sc = Scoss(id_scoss="dasdsa", threshold=[0,0,0])
sc.add_file('tests/data/a.cpp')
sc.add_file('tests/data/b.cpp')

for i in sc.get_copy():
    print(i['file1'],i['score'])
print("______________________________________")
print(sc.get_list_idxfile())