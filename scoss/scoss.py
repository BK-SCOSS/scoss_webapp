from __future__ import absolute_import
from similarities import all_similarities
from sctokenizer import Source
import os
import glob
from jinja2 import Environment
class Scoss():
	def __init__(self, language, id_scoss=None, measures={'similarity_1': 0, 'similarity_2':0, 'similarity_3':0}):
		self.id_scoss = id_scoss
		self.id_file = 0
		self.list_file = {} #save id file
		self.list_source = [] # save source file
		self.list_score_similarity = [] #save similarity between files
		self.measures_similarity = []
		self.copy_code = []
		self.threshold = []
		self.language = language
		# if len(threshold) != len(measures) and len(threshold) < 3:
		for mea in measures:
			self.threshold.append(int(measures[mea]))
			for simi in all_similarities:
				if mea == simi.get_name():
					self.measures_similarity.append(simi)
	def get_idx_scoss(self):
		return self.id_scoss

	def check_file(self, filepath):
		for file in self.list_file:
			if self.list_file[file] == filepath:
				return True
		return False

	def add_file(self, filepath):
		if not self.check_file(filepath):
			self.list_file[self.id_file] = filepath
			self.list_source.append(Source.from_file(filepath, lang=self.language))
			self.id_file += 1
			if len(self.list_source) > 1:
				self.update_similarity(self.list_source)
		else:
			position = -1
			for index, value in enumerate(self.list_file.keys()):
				if value == self.get_id_file(filepath):
					position = index
			if position != -1:
				self.list_source[position] = Source.from_file(filepath, lang=self.language)
				if len(self.list_source) > 1:
					self.compute_similarity(self.list_source)
	def add_list_file(self, dirpath):
		for file in glob.glob(dirpath, recursive=True):
			self.add_file(file)

	def add_zip(self, filepath):
		pass

	def compute_similarity(self, list_source):
		self.list_score_similarity = []
		self.copy_code = []
		for i in range(1, len(list_source)):
			simi = []
			for j in range(0,i):
				tem = []
				check_score = 0
				for k in range(len(self.measures_similarity)):
					score = self.measures_similarity[k].get_similarity(list_source[i], list_source[j])
					tem.append(score)
					if score >= self.threshold[k]:
						check_score += 1
				if check_score == 3:
					self.copy_code.append([i,j])
				simi.append(tem)	
			self.list_score_similarity.append(simi)
			
	def update_similarity(self, list_source):
		simi = []
		for i in range(len(list_source) -1):
			tem = []
			check_score = 0
			score = 0
			for k in range(len(self.measures_similarity)):
				score = self.measures_similarity[k].get_similarity(list_source[-1], list_source[i])
				tem.append(score)
				if score >= self.threshold[k]:
					check_score += 1
			if check_score == 3:
				self.copy_code.append([(len(list_source) -1),i])
			simi.append(tem)
		self.list_score_similarity.append(simi)

	def get_score(self):
		list_copy = []
		for i in range(len(self.copy_code)):
			dic = {}
			dic['file1'] = self.list_file[self.copy_code[i][0]]
			dic['file2'] = self.list_file[self.copy_code[i][1]]
			dic['score'] = self.list_score_similarity[(self.copy_code[i][0]) - 1][(self.copy_code[i][1])]
			list_copy.append(dic)

		return list_copy
	def get_score_id(self, idx):

		list_score = []
		if idx >= 1 and idx < self.id_file:
			for i in self.list_score_similarity[idx-1]:
				list_score.append(i)
			for i in range(int(idx)+1,len(self.list_score_similarity)):
				list_score.append(self.list_score_similarity[i][idx])
		if idx == 0:
			for i in range(0,len(self.list_score_similarity)):
				list_score.append(self.list_score_similarity[i][idx])
		return list_score

	def get_list_idx_file(self):
		return self.list_file

	def get_id_file(self, filepath):
		if self.check_file(filepath):
			for id_file in self.list_file:
				if self.list_file[id_file] == filepath:
					return id_file

	def saveWebPage(self, url):
		HTML1 = """<!DOCTYPE html>
		<html lang="en">
		<head>
			<meta charset="UTF-8">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<title>Result</title>
			<style>
				table {
				font-family: arial, sans-serif;
				border-collapse: collapse;
				}
				
				td, th {
				border: 1px solid #dddddd;
				text-align: left;
				padding: 8px;
				}
				
				tr:nth-child(even) {
				background-color: #dddddd;
				}
				</style>
		</head>
		<body>

		<h2>Result</h2>

		<table>
			<tr>
			<th>File1</th>
			<th>File2</th>
			<th>Score</th>
			</tr>
			<tr>
			{%for res in result%}
			<td><a href="{{links[loop.index-1]}}"  target="_blank" >{{res['file1']}}</a></td>
			<td><a href="{{links[loop.index-1]}}"  target="_blank" >{{res['file2']}}</a></td>
			<td><a href="{{links[loop.index-1]}}"  target="_blank" >{{res['score']}}</a></td>
			</tr>
			{%endfor%}
		</table>

		</body>
		</html>
		"""
		HTML2 = """
		<!DOCTYPE html>
		<html>
		<body>
		<h2>File</h2>
		<table style="width:75%">
		<tr>
			<th>{{file1}}</th>
			<th>{{file2}}</th> 
		</tr>
		<tr>
			<td>{{data1}}</td>
			<td>{{data2}}</td>
		</tr>
		</table>
		</body>
		</html>
		"""
		result = self.get_score()
		index1 = -1
		index2 = -1
		index_save_file = 0
		position_file = []
		links = []
		for res in result:
			for index, value in enumerate(self.list_file.keys()):
				if value == self.get_id_file(res['file1']):
					index1 = index
				if value == self.get_id_file(res['file2']):
					index2 = index
			position_file.append([index1, index2])
		for pos in position_file:
			
			token_per_lines1 = {}
			token_per_lines2 = {}
			lines1 = []
			lines2 = []
			for token1 in self.list_source[pos[0]].tokenize():
				if token1.position[0] in token_per_lines1.keys():
					token_per_lines1[token1.position[0]].append(token1.token_value)
				else:
					token_per_lines1[token1.position[0]] = []
					token_per_lines1[token1.position[0]].append(token1.token_value)
			for token2 in self.list_source[pos[1]].tokenize():
				if token2.position[0] in token_per_lines2.keys():
					token_per_lines2[token2.position[0]].append(token2.token_value)
				else:
					token_per_lines2[token2.position[0]] = []
					token_per_lines2[token2.position[0]].append(token2.token_value)
			# print(token_per_lines1)
			for line1 in token_per_lines1:
				for line2 in token_per_lines2:
					count = 0
					for i in token_per_lines1[line1]:
						for j in token_per_lines2[line2]:
							if i == j:
								count += 1
					# print(count,len(token_per_lines1[line1]), len(token_per_lines2[line2]), line1, line2)
					if count/len(token_per_lines1[line1]) > 0.75 and count/len(token_per_lines2[line2]) > 0.75:
						lines1.append(line1-1)
						lines2.append(line2-1)
			with open(self.list_file[pos[0]], 'r') as file:
				data1 = file.read().split('\n')
	
			with open(self.list_file[pos[1]], 'r') as file:
				data2 = file.read().split('\n') 
			for i in range(len(data1)):
				data1[i] = data1[i].replace('<', '&lt').replace('>', '&gt')
				if i in list(set(lines1)):
					data1[i] = '<pre style="color: red">'+ str(i+1)+ '    '+ data1[i] + '</pre>'
				else:
					data1[i] = '<pre >'+ str(i+1)+ '	' + data1[i] + '</pre>'
			for i in range(len(data2)):
				data2[i] = data2[i].replace('<', '&lt').replace('>', '&gt')
				if i in list(set(lines2)):
					data2[i] =  '<pre style="color: red">'+  str(i+1)+ '	'+  data2[i] + '</pre>'
				else:
					data2[i] = '<pre >'+ str(i+1)+ '	'+ data2[i] + '</pre>'
			
			mess = Environment().from_string(HTML2).render(file1=self.list_file[pos[0]], file2=self.list_file[pos[1]], \
				data1=' '.join(data1), data2=' '.join(data2))
			index_save_file += 1
			name_file = 'result_' + str(index_save_file) + '.html'
			links.append(name_file)

			with open(os.path.join(url, name_file), 'w') as file:
				file.write(mess)

		page = Environment().from_string(HTML1).render(result=result, links=links)
		with open(os.path.join(url, 'result.html'), 'w') as file:
			file.write(page)