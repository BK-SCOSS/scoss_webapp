import os
import glob
import enum
import mosspy 
import time
import pandas as pd
from collections import OrderedDict
from bs4 import BeautifulSoup
from jinja2 import Environment
try:
    from urllib.request import urlopen
except ImportError:
    from urllib2 import urlopen

class SMossState(enum.Enum):
    INIT = 0 
    RUNNING = 1 
    CLOSE = 3

class SMoss():
    __id = 0

    def __init__(self, lang, userid=43511):
        
        SMoss.__id = 1
        self.id = SMoss.__id

        self.__userid = userid
        if lang == 'cpp':
            lang = 'cc'
        self.__lang = lang
        self.__state = SMossState.INIT
        self.__threshold = 0
        self.__pending_pool = OrderedDict()

        self.__matches = []
        self.__similarity_matrix = dict()
        self.__matches_file = dict()

    def set_threshold(self, threshold: float):
        self.__threshold = threshold
    
    def add_file(self, file, mask=None):
        if self.__state != SMossState.CLOSE:
            if mask is None:
                mask = file
            if mask in self.__pending_pool.keys():
                raise ValueError(f'mask:{mask} is already exist')
            self.__pending_pool[mask] = file
        else:
            raise ValueError('Cannot add file after running')

    def update_file(self, file, mask=None):
        if self.__state != SMossState.CLOSE:
            if mask is None:
                mask = file
            self.__pending_pool[mask] = file
        else:
            raise ValueError('Cannot update file after running')

    def add_file_by_wildcard(self, dirpath, recursive=True):
        if self.__state != SMossState.CLOSE:
            for file in glob.glob(dirpath, recursive=recursive):
                self.add_file(file)
        else:
            raise ValueError('Cannot add file after running')

    def get_matches(self):
        if self.__state == SMossState.INIT:
            self.run()
        matches = []
        for match in self.__matches:
            copied_match = match.copy()
            if 'link' in copied_match:
                del copied_match['link']
            matches.append(copied_match)
        return matches

    def get_similarity_matrix(self):
        if self.__state == SMossState.INIT:
            self.run()
        return self.__similarity_matrix

    def get_matches_file(self):
        if self.__state == SMossState.INIT:
            self.run()
        return self.__matches_file
    
    def save_matches_to_csv(self, filepath):
        if self.__state == SMossState.INIT:
            self.run()
        new_matches = []
        for match in self.__matches:
            dic = {}
            dic['source1'] = match['source1']
            dic['source2'] = match['source2']
            for metric, score in match['scores'].items():
                dic[metric] = score
            new_matches.append(dic)
        df_data = pd.DataFrame.from_dict(new_matches)
        name_file = 'result_' +str(int(time.time())) +'.csv'
        df_data.to_csv(os.path.join(filepath, name_file))

    def parse_html_table(self, url):
        html = urlopen(url).read().decode()
        soup = BeautifulSoup(html, features="lxml")
        tds = soup.find_all('td')
        i = 0
        self.__matches = []
        while i < len(tds):
            score = int(tds[0].contents[0].contents[0][-4:-2])/100
            if score < self.__threshold:
                i += 3
                continue
            a_score = {'moss_score': score}
            src1 = tds[i].contents[0].contents[0].split()[0]
            src2 = tds[i+1].contents[0].contents[0].split()[0]

            # Construct matches
            a_match = {}
            a_match['source1'] = src1
            a_match['source2'] = src2
            a_match['scores'] = a_score
            a_match['link'] = tds[0].contents[0].attrs['href']
            self.__matches.append(a_match)

            # Construct similarity_matrix
            self.__similarity_matrix[src1] = {src2:a_score}
            self.__similarity_matrix[src2] = {src1:a_score}

            # # Construct matches_file
            base_url = os.path.dirname(a_match['link'])
            summary_html = self.url_content_to_str(a_match['link'])
            soup = BeautifulSoup(summary_html, 'lxml')
            html_strs = []
            for more_url in soup.find_all('frame'):
                html_str = self.url_content_to_str(base_url + '/' + more_url.get('src'))
                soup = BeautifulSoup(html_str, 'lxml')
                for a in soup.findAll('a'):
                    del a['href']
                html_strs.append(str(soup))
            with open('./scoss/assets/smoss_comparison.html', mode='r') as f:
                big_html_string = f.read()
            big_html_string = big_html_string.replace('<<<top>>>', html_strs[0])
            big_html_string = big_html_string.replace('<<<src1>>>', html_strs[1])
            big_html_string = big_html_string.replace('<<<src2>>>', html_strs[2])
            self.__matches_file[src1] = {src2:big_html_string}
            self.__matches_file[src2] = {src1:big_html_string}
            # with open(os.path.join('./tests/smoss_result/', 'big_all_html.html'), 'w') as file:
            #     file.write(big_html_string)

            i += 3

    def run(self):
        if self.__state != SMossState.CLOSE:
            m = mosspy.Moss(self.__userid, self.__lang)
            for mask, file in self.__pending_pool.items():
                m.addFile(file, mask)
            url = m.send()
            if url == '':
                raise ValueError("MOSS Server returned empty url. Please check userid.")
            self.parse_html_table(url)
            self.__state = SMossState.CLOSE
        else:
            raise ValueError("Can only execute run function once.")

    def url_content_to_str(self, url):
        html_str = urlopen(url).read().decode()
        return html_str

    def process_url(self, url, file_name, path):
        def save_html(url, file_name):
            html_str = self.url_content_to_str(url)
            with open(os.path.join(path, file_name), 'w') as file:
                file.write(html_str)

        save_html(url, file_name)
        html = self.url_content_to_str(url)
        soup = BeautifulSoup(html, 'lxml')
        base_url = os.path.dirname(url)
        for more_url in soup.find_all('frame'):
            file_name = more_url.get('src')   
            save_html(base_url + '/' + file_name, file_name)
            
    def save_as_html(self, output_dir=None):
        if self.__state == SMossState.INIT:
            self.run()
        HTML1 = ""
        with open('./scoss/assets/summary.html', mode='r') as f:
            HTML1 = f.read()

        if len(self.__matches) != 0:
            heads = [x for x in self.__matches[0].keys() if x != 'link']
            links = []
            index_file = 0
            for match in self.__matches:
                dic = {}
                dic['source1'] = match['source1']
                dic['source2'] = match['source2']
                dic['scores'] = {}

                name_file = 'comparison_' + str(index_file) +'.html'
                index_file += 1
                metric = 'moss_score'
                C = int(match['scores'][metric]*255)
                R = C
                G = 0
                B = 0;
                span = '<span style="color: rgb({}, {}, {})">'.format(R,G,B) + str(format(match['scores'][metric]*100, '.2f')) +'%</span>'
                dic['scores'][metric] = [name_file, span]
                links.append(dic)
                self.process_url(match['link'], name_file, output_dir)
            page = Environment().from_string(HTML1).render(heads=heads, links=links)
            with open(os.path.join(output_dir, 'summary.html'), 'w') as file:
                file.write(page)
    
    def set_metric_threshold(self, metric_name, threshold: float):
        raise ValueError("smoss doesn't support this function. Use set_threshold() instead.")

    def add_metric(self, metric, threshold: float=0.0, exist_ok=False):
        raise ValueError("smoss doesn't support this function.")

    def add_source_str(self, source_str, mask):
        raise ValueError("smoss doesn't support this function.")

    def update_source_str(self, source_str, mask):
        raise ValueError("smoss doesn't support this function.")

    def check_similarity(self, src):
        raise ValueError("smoss doesn't support this function.")

    def align_source(self, src):
        raise ValueError("smoss doesn't support this function.")
