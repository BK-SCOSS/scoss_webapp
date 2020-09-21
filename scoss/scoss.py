from __future__ import absolute_import

from scoss.metrics import MetricList, Metric
from sctokenizer import Source
from jinja2 import Environment
from collections import OrderedDict

import os
import glob
import enum

class ScossState(enum.Enum):
    INIT = 0 
    RUNNING = 1 
    CLOSE = 3

class Scoss():
    __id = 0

    def __init__(self, lang, used_metrics=None):
        Scoss.__id= 1
        self.id = Scoss.__id

        self.__lang = lang
        self.__state = ScossState.INIT
        
        self.__metric_list = MetricList(used_metrics)
        self.__thresholds = OrderedDict()
        for metric_name in self.__metric_list.get_metric_names():
            self.__thresholds[metric_name] = 0.0
        
        self.__sources = OrderedDict()
        self.__pending_pool = OrderedDict()

        self.__similarity_matrix = dict()
        self.__alignment_matrix = dict()

    def set_metric_threshold(self, metric_name, threshold: float):
        if metric_name not in self.__thresholds:
            raise ValueError(f'metric_name:{metric_name} is not in metric_list')
        self.__thresholds[metric_name] = threshold

    def add_metric(self, metric, threshold: float=0.0, exist_ok=False):
        if self.__state != ScossState.INIT:
            raise ValueError('Cannot add metric after running')

        self.__metric_list.add_metric(metric, exist_ok=exist_ok)
        if isinstance(metric, Metric):
            metric_name = metric.get_name()
        else:
            metric_name = metric
        self.__thresholds[metric_name] = threshold

    def add_source_str(self, source_str, mask):
        if mask in self.__sources.keys() or mask in self.__pending_pool.keys():
            raise ValueError(f'mask:{mask} is already exist')
        src = Source.from_str(source_str, lang=self.__lang)
        src.name = mask
        self.__pending_pool[mask] = src 

        if self.__state == ScossState.RUNNING:
            self.run()


    def update_source_str(self, source_str, mask):
        src = Source.from_str(source_str, lang=self.__lang)
        src.name = mask
        self.__pending_pool[mask] = src

        if self.__state == ScossState.RUNNING:
            self.run()

    def add_file(self, file, mask=None):
        if mask is None:
            mask = file
        if mask in self.__sources.keys() or mask in self.__pending_pool:
            raise ValueError(f'mask:{mask} is already exist')
        src = Source.from_file(file, lang=self.__lang)
        src.name = mask
        self.__pending_pool[mask] = src

        if self.__state == ScossState.RUNNING:
            self.run()

    def update_file(self, file, mask=None):
        if mask is None:
            mask = file
        src = Source.from_file(file, lang=self.__lang)
        src.name = mask
        self.__pending_pool[mask] = src

        if self.__state == ScossState.RUNNING:
            self.run()

    def add_file_by_wildcard(self, dirpath, recursive=True):
        for file in glob.glob(dirpath, recursive=recursive):
            self.add_file(file)

    def check_similarity(self, src):
        """check_similarity.
            Check similarity between src and current sources 

        Args:
            src:
        """
        ret = dict()
        for other_mask, other in self.__sources.items():
            scores = self.__metric_list.evaluate(src, other)
            ret[other_mask] = scores

        return ret

    def align_source(self, src):
        """align_source.

        Args:
            src:
        """
        ret = dict()
        for other_mask, other in self.__sources.items():
            alignments = self.__metric_list.align_source(src, other)
            ret[other_mask] = alignments

        return ret

    def run(self):
        """run.
            compute similarity source from pending_pool vs solved sources
        """
        self.__state = ScossState.RUNNING
        pending_pool_items = list(self.__pending_pool.items())
        for name, src in pending_pool_items:
            scores = self.check_similarity(src)
            alignments = self.align_source(src)
            self.__similarity_matrix[name] = scores
            self.__alignment_matrix[name] = alignments
            
            for other_name, score in scores.items():
                self.__similarity_matrix[other_name][name] = score

            for other_name, alignment in alignments.items():
                self.__alignment_matrix[other_name][name] = alignment

            self.__sources[name] = src
            self.__pending_pool.pop(name)

    def get_similarity_matrix(self):
        self.run()
        return self.__similarity_matrix

    def sort_matches(self, matches, by=None):
        """sort_matches.

        Args:
            matches:
            by: 'sum': sort by sum of all metrics
                List[metric_name]: sort by order in this list
        """
        # TODO: Vien 
        pass

    def get_matches(self, or_thresholds=False, and_thresholds=False):
        """get_similarity_scores.

        Args:
            or_thresholds: a match is detected if similarity score in any metrics is greater than threshold
            and_thresholds: a match is detected if similarity score in all metrics is greater than threshold
        """
        if or_thresholds and and_thresholds:
            raise ValueError('Cannot trim result by both OR and AND thresholds')
        self.run()
        match_dict = {}
        for name, score_dict in self.__similarity_matrix.items():
            for other_name, scores in score_dict:
                key = hash(name) ^ hash(other_name)
                match = {}
                match['source1'] = name
                match['source2'] = other_name
                match['scores'] = scores
                match_dict[key] = match

        matches = match_dict.values()

        if not or_thresholds and not and_thresholds:
            return self.sort_matches(matches, by='sum')
        elif or_thresholds:
            # TODO: (Vien) implement trim matches.  
            pass
        elif and_thresholds:
            # TODO: (Vien) implement this
            pass

    def save_matches_to_csv(self, or_thresholds=False, and_thresholds=False):
        # TODO: (Vien) 
        pass

    def save_as_html(self, trimmed=True, output_dir=None):
        HTML1 = ""
        HTML2 = ""
        with open('./assets/summary.html', mode='r') as f:
            HTML1 = f.read()
        with open('./assets/comparison.html', mode='r') as f:
            HTML2 = f.read()

        # TODO: Implement this
        # result = self.get_score()
        # index1 = -1
        # index2 = -1
        # index_save_file = 0
        # position_file = []
        # links = []
        # for res in result:
        #     for index, value in enumerate(self.list_file.keys()):
        #         if value == self.get_id_file(res['file1']):
        #             index1 = index
        #         if value == self.get_id_file(res['file2']):
        #             index2 = index
        #     position_file.append([index1, index2])
        # for pos in position_file:

        #     token_per_lines1 = {}
        #     token_per_lines2 = {}
        #     lines1 = []
        #     lines2 = []
        #     for token1 in self.list_source[pos[0]].tokenize():
        #         if token1.position[0] in token_per_lines1.keys():
        #             token_per_lines1[token1.position[0]].append(
        #                 token1.token_value)
        #         else:
        #             token_per_lines1[token1.position[0]] = []
        #             token_per_lines1[token1.position[0]].append(
        #                 token1.token_value)
        #     for token2 in self.list_source[pos[1]].tokenize():
        #         if token2.position[0] in token_per_lines2.keys():
        #             token_per_lines2[token2.position[0]].append(
        #                 token2.token_value)
        #         else:
        #             token_per_lines2[token2.position[0]] = []
        #             token_per_lines2[token2.position[0]].append(
        #                 token2.token_value)
        #     # print(token_per_lines1)
        #     for line1 in token_per_lines1:
        #         for line2 in token_per_lines2:
        #             count = 0
        #             for i in token_per_lines1[line1]:
        #                 for j in token_per_lines2[line2]:
        #                     if i == j:
        #                         count += 1
        #             # print(count,len(token_per_lines1[line1]), len(token_per_lines2[line2]), line1, line2)
        #             if count/len(token_per_lines1[line1]) > 0.75 and count/len(token_per_lines2[line2]) > 0.75:
        #                 lines1.append(line1-1)
        #                 lines2.append(line2-1)
        #     with open(self.list_file[pos[0]], 'r') as file:
        #         data1 = file.read().split('\n')

        #     with open(self.list_file[pos[1]], 'r') as file:
        #         data2 = file.read().split('\n')
        #     for i in range(len(data1)):
        #         data1[i] = data1[i].replace('<', '&lt').replace('>', '&gt')
        #         if i in list(set(lines1)):
        #             data1[i] = '<pre style="color: red">' + \
        #                 str(i+1) + '    ' + data1[i] + '</pre>'
        #         else:
        #             data1[i] = '<pre >' + str(i+1) + '	' + data1[i] + '</pre>'
        #     for i in range(len(data2)):
        #         data2[i] = data2[i].replace('<', '&lt').replace('>', '&gt')
        #         if i in list(set(lines2)):
        #             data2[i] = '<pre style="color: red">' + \
        #                 str(i+1) + '	' + data2[i] + '</pre>'
        #         else:
        #             data2[i] = '<pre >' + str(i+1) + '	' + data2[i] + '</pre>'

        #     mess = Environment().from_string(HTML2).render(file1=self.list_file[pos[0]], file2=self.list_file[pos[1]],
        #                                                    data1=' '.join(data1), data2=' '.join(data2))
        #     index_save_file += 1
        #     name_file = 'result_' + str(index_save_file) + '.html'
        #     links.append(name_file)

        #     with open(os.path.join(url, name_file), 'w') as file:
        #         file.write(mess)

        # page = Environment().from_string(HTML1).render(result=result, links=links)
        # with open(os.path.join(url, 'result.html'), 'w') as file:
        #     file.write(page)

