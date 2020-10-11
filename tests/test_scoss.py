from sctokenizer import Source
from scoss.metrics.token_based_metric import TokenBasedMetric
from scoss.metrics import CountOperator, SetOperator, HashOperator
from scoss import Scoss

# src1 = Source.from_file('./data/a.cpp')
src2 = Source.from_file('./tests/data/b.cpp')
for token in src2.tokenize():
    print(token)

def test_scoss():
    sc = Scoss(lang='cpp')
    sc.add_metric('count_operator')
    sc.add_metric('set_operator')
    sc.add_file('./tests/data/a.cpp')
    sc.add_file('./tests/data/b.cpp')
    sc.add_file('./tests/data/c.cpp')
    sc.run()


def test_scoss_or():
    sc = Scoss(lang='cpp')
    sc.add_metric('count_operator', 1.0)
    sc.add_metric('set_operator')
    sc.add_file('./tests/data/a.cpp')
    sc.add_file('./tests/data/b.cpp')
    sc.add_file('./tests/data/c.cpp')
    sc.run()
    print(sc.get_matches(or_thresholds=True))

def test_scoss_and():
    sc = Scoss(lang='cpp')
    sc.add_metric('count_operator', 1.0)
    sc.add_metric('set_operator')
    sc.add_file('./tests/data/a.cpp')
    sc.add_file('./tests/data/b.cpp')
    sc.add_file('./tests/data/c.cpp')
    sc.run()
    print(sc.get_matches(and_thresholds=True))
    sc.save_as_html('./tests/result/')

def test_scoss_csv():
    sc = Scoss(lang='cpp')
    sc.add_metric('count_operator')
    sc.add_metric('set_operator')
    sc.add_file('./tests/data/a.cpp')
    sc.add_file('./tests/data/b.cpp')
    sc.add_file('./tests/data/c.cpp')
    sc.run()
    sc.save_matches_to_csv('tests/result/')

def test_scoss_save_html():
    sc = Scoss(lang='cpp')
    sc.add_metric('count_operator', 1.0)
    sc.add_metric('set_operator')
    sc.add_file('./tests/data/a.cpp', mask='Thai')
    sc.add_file('./tests/data/b.cpp', mask='Vien')
    sc.add_file('./tests/data/c.cpp', mask='Ngoc')
    sc.run()
    # print(sc.get_aligment_matrix())
    # sc.save_as_html('./tests/result/', and_thresholds=True)


if __name__ == '__main__':
    # python3 tests/test_scoss.py 
    # test_scoss_or()
    # test_scoss_and()
    # test_scoss_csv()
    test_scoss_save_html()
