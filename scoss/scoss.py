from __future__ import absolute_import
from similarities import all_similarities
from sctokenizer import Source
class Scoss():
	def __init__(self, id_scoss=None, measures={'similarity_1': 0, 'similarity_2':0, 'similarity_3':0} ):
		self.id_scoss = id_scoss
		self.id_file = 0
		self.list_file = {} #save id file
		self.list_source = [] # save source file
		self.list_score_similarity = [] #save similarity between files
		self.measures_similarity = []
		self.copy_code = []
		self.threshold = []
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
			self.list_source.append(Source.from_file(filepath))
			self.id_file += 1
			if len(self.list_source) > 1:
				self.update_similarity(self.list_source)
		else:
			position = -1
			for index, value in enumerate(self.list_file.keys()):
				if value == self.get_id_file(filepath):
					position = index
			if position != -1:
				self.list_source[position] = Source.from_file(filepath)
				if len(self.list_source) > 1:
					self.compute_similarity(self.list_source)

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
			for file in self.list_file:
				if self.list_file[file] == filepath:
					return file
