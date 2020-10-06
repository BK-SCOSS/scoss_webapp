import os
import glob
import mosspy 
from collections import OrderedDict
from bs4 import BeautifulSoup
from jinja2 import Environment
try:
    from urllib.request import urlopen
except ImportError:
    from urllib2 import urlopen

class SMoss():
    __id = 0

    def __init__(self, lang, userid=12345):
        
        SMoss.__id = 1
        self.id = SMoss.__id

        self.__userid = userid
        if lang == 'cpp':
            lang = 'cc'
        self.__lang = lang
        self.__threshold = 0
        self.__pending_pool = OrderedDict()

        self.__matches = []

    def get_matches(self):
        matches = []
        if not self.__matches:
            print('matches list is empty! You should execute run function first!')
        else:
            for match in self.__matches:
                copied_match = match.copy()
                if 'link' in copied_match:
                    del copied_match['link']
                matches.append(copied_match)
        return matches

    def set_threshold(self, threshold: float):
        self.__threshold = threshold
    
    def add_file(self, file, mask=None):
        if mask is None:
            mask = file
        if mask in self.__pending_pool.keys():
            raise ValueError(f'mask:{mask} is already exist')
        self.__pending_pool[mask] = file
    
    def update_file(self, file, mask=None):
        if mask is None:
            mask = file
        self.__pending_pool[mask] = file

    def add_file_by_wildcard(self, dirpath, recursive=True):
        for file in glob.glob(dirpath, recursive=recursive):
            self.add_file(file)
    
    def save_matches_to_csv(self, filepath, or_thresholds=False, and_thresholds=False):
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
        # print(tds[0].contents[0].attrs['href'])
        # print(tds[0].contents[0].contents[0])
        i = 0
        self.__matches = []
        while i < len(tds):
            score = int(tds[0].contents[0].contents[0][-4:-2])/100
            if score < self.__threshold:
                i += 3
                continue
            a_match = {}
            a_match['source1'] = tds[i].contents[0].contents[0].split()[0]
            a_match['source2'] = tds[i+1].contents[0].contents[0].split()[0]
            a_score = {'moss_score': score}
            a_match['scores'] = a_score
            a_match['link'] = tds[0].contents[0].attrs['href']
            self.__matches.append(a_match)
            i += 3

    def process_url(self, url, file_name, path):
        def save_html(url, file_name):
            html_str = urlopen(url).read().decode()
            with open(os.path.join(path, file_name), 'w') as file:
                file.write(html_str)

        save_html(url, file_name)
        response = urlopen(url)
        html = response.read()
        soup = BeautifulSoup(html, 'lxml')
        base_url = os.path.dirname(url)
        # print('base_url = ', base_url)
        for more_url in soup.find_all('frame'):
            file_name = more_url.get('src')    
            save_html(base_url + '/' + file_name, file_name)

    def save_as_html(self, output_dir=None):
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

    def run(self):
        m = mosspy.Moss(self.__userid, self.__lang)
        for mask, file in self.__pending_pool.items():
            m.addFile(file, mask)
        url = m.send()
        self.parse_html_table(url)
