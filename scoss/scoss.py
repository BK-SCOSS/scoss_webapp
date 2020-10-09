from __future__ import absolute_import

from scoss.metrics import MetricList, Metric, all_metrics
from scoss.metrics.token_based_metric import *
from sctokenizer import Source
from jinja2 import Environment
from collections import OrderedDict
import pandas as pd
import os
import glob
import enum
import time
class ScossState(enum.Enum):
    INIT = 0 
    RUNNING = 1 
    CLOSE = 3

class Scoss():
    __id = 0

    def __init__(self, lang, used_metrics=None):
        """__init__.

        Args:
            lang:
            used_metrics:
        """
        Scoss.__id= 1
        self.id = Scoss.__id

        self.__lang = lang
        self.__state = ScossState.INIT
        self.__thresholds = OrderedDict()
       
        self.__metric_list = MetricList(used_metrics)
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

        # if self.__metric_list is None:
        #     self.__metric_list = MetricList(all_metrics)
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
        # print(self.__similarity_matrix)
        # print(self.__alignment_matrix)
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
        matches = list(matches)
        
        if by == 'sum' or by == None:
            matches.sort(reverse=True, key=lambda match:  sum(match['scores'].values()))
            return matches
        else:
            matches.sort(reverse=True, key=lambda match:  match['scores'][by])
            return matches

       
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
            for other_name, scores in score_dict.items():
                key = hash(name) ^ hash(other_name)
                match = {}
                match['source1'] = name
                match['source2'] = other_name
                match['scores'] = scores
                match_dict[key] = match

        matches = list(match_dict.values())
      
        if not or_thresholds and not and_thresholds:
            return self.sort_matches(matches, by='sum')
        elif or_thresholds:
            index = 0
            for i in range(len(matches)):
                for metric, score in matches[i]['scores'].items():
                    if score > self.__thresholds[metric]:
                        matches[index] = matches[i] 
                        index += 1
                        break
            return self.sort_matches(matches[:index], by='sum')
        elif and_thresholds:
            index = 0
            for i in range(len(matches)):
                check = True
                for metric, score in matches[i]['scores'].items():
                    if score < self.__thresholds[metric]:
                        check = False
                if check :
                    matches[index] = matches[i] 
                    index += 1
            
            return self.sort_matches(matches[:index], by='sum')
                  
        

    def save_matches_to_csv(self, filepath, or_thresholds=False, and_thresholds=False):
        """save_matches_to_csv.
        Args:
            filepath: save to filepath
            or_thresholds: see get_matches, use get_matches 
            and_thresholds:
        """
        matches = self.get_matches(or_thresholds, and_thresholds)
        new_matches = []
        for match in matches:
            dic = {}
            dic['source1'] = match['source1']
            dic['source2'] = match['source2']
            for metric, score in match['scores'].items():
                dic[metric] = score
            new_matches.append(dic)
        df_data = pd.DataFrame.from_dict(new_matches)
        name_file = 'result_' +str(int(time.time())) +'.csv'
        df_data.to_csv(os.path.join(filepath, name_file))

    def save_as_html(self, output_dir='./', or_thresholds=False, and_thresholds=True):
        """save_as_html.
            use self.__alignment_matrix to align 2 source, 

        Args:
            trimmed:
            output_dir: save all html files in output_dir, if output_dir=None -> donot save
        Return:
            ret: A dictionary of html files. example: {'summary.html': HTML1, 'match1.html': HTML2, ....}
        """
        HTML1 = ""
        HTML2 = ""
        with open('./scoss/assets/summary.html', mode='r') as f:
            HTML1 = f.read()
        with open('./scoss/assets/comparison.html', mode='r') as f:
            HTML2 = f.read()

        matches = self.get_matches(or_thresholds, and_thresholds)
        new_matches = []
        for match in matches:
            dic = {}
            dic['source1'] = match['source1']
            dic['source2'] = match['source2']
            for metric, score in match['scores'].items():
                dic[metric] = score
            new_matches.append(dic)
        if len(new_matches) != 0:
            heads = new_matches[0].keys()
            match_dict = {}
            for name, score_dict in self.__alignment_matrix.items():
                for other_name, scores in score_dict.items():
                    key = hash(name) ^ hash(other_name)
                    match = {}
                    match['source1'] = name
                    match['source2'] = other_name
                    match['scores'] = scores
                    match_dict[key] = match
            matches_alignment = list(match_dict.values())

            links = []
            index_file = 0
            for match in matches_alignment:
                # print(match)
                dic = {}
                dic['source1'] = match['source1']
                dic['source2'] = match['source2']
                dic['scores'] = {}
                for metric, score in match['scores'].items():
                    src1 = self.__sources[dic['source1']]
                    data1 = []
                    for r in all_metrics[-1].compact_line(src1.tokenize()):
                        row = []
                        for c in r:
                            row.append(c.token_value)
                        data1.append(' '.join(row))
                    src2 = self.__sources[dic['source2']]
                    data2 = []
                    for r in all_metrics[-1].compact_line(src2.tokenize()):
                        row = []
                        for c in r:
                            row.append(c.token_value)
                        data2.append(' '.join(row))
                    # with open(match['source1'], 'r') as f:
                    #     data1 = f.read().split('\n')
                    # with open(match['source2'], 'r') as f:
                    #     data2 = f.read().split('\n')
                    data1 = [i.replace('<', '&lt').replace('>', '&gt') for i in data1]
                    data2 = [i.replace('<', '&lt').replace('>', '&gt') for i in data2]
                    html1 = ''
                    html2 = ''
                    for line in score:
                
                        if line[0] == -1 :
                           
                            html1 += '<pre >  </pre>'
                            temp2 = '<pre >'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
                            html2 += temp2
                        elif line[1] == -1 :
                            html2 += '<pre >  </pre>'
                            temp1 = '<pre >'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
                            html1 += temp1
                        elif line[0] != -1 and line[0] != -1:
                            
                            index1 = line[0]
                            index2 = line[1]
                            if line[2] >=0.25 and line[2] <0.75:
                                temp1 = '<pre style="color: #ffb600">'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
                                html1 += temp1
                                temp2 = '<pre style="color: #ffb600">'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
                                html2 += temp2
                            elif line[2] >= 0.75:
                                temp1 = '<pre style="color: red">'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
                                html1 += temp1
                                temp2 = '<pre style="color: red">'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
                                html2 += temp2
                            else:
                                temp1 = '<pre style="color: black">'+  str(line[0])+ '	'+  data1[line[0]-1] + '</pre>'
                                html1 += temp1
                                temp2 = '<pre style="color: black">'+  str(line[1])+ '	'+  data2[line[1]-1] + '</pre>'
                                html2 += temp2
                    name_file = 'comparison_' + str(index_file) +'.html'
                    index_file += 1
                    for new_match in new_matches:
                        if new_match['source1'] == match['source1'] and \
                            new_match['source2'] == match['source2'] :
                            C = int(new_match[metric]*255)
                            R = C
                            G = 0
                            B = 0;
                            span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(new_match[metric]*100, '.2f')) +'%</span>'
                            dic['scores'][metric] = [name_file, span]
                    mess = Environment().from_string(HTML2).render(file1=match['source1'], file2=match['source2'], \
                                    metric=metric, score=span, \
                                    data1=html1, data2=html2)
                    with open(os.path.join(output_dir, name_file), 'w') as file:
                        file.write(mess)
                links.append(dic)
        page = Environment().from_string(HTML1).render(heads=heads, links=links)
        with open(os.path.join(output_dir, 'summary.html'), 'w') as file:
            file.write(page)

