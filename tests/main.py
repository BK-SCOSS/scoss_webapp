import os
import sys
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(WORKING_DIR, '../scoss'))
from scoss import Scoss
from sctokenizer import Source

# src1 = Source.from_file('tests/data/a.cpp', lang='cpp')
# src2 = Source.from_file('tests/data/b.cpp', lang='cpp')

sc = Scoss(id_scoss="dasdsa")
sc.add_file('tests/data/a.cpp')
sc.add_file('tests/data/a.cpp')
sc.add_file('tests/data/a.cpp')
sc.add_file('tests/data/b.cpp')
sc.add_file('tests/data/c.cpp')
for i in sc.get_score():
    print(i)
print("______________________________________")
print(sc.get_list_idx_file())