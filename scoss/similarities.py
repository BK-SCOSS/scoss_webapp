from __future__ import absolute_import
from sctokenizer.token import TokenType
import hashlib

class Similarity():
	name = None

	def __init__(self):
		pass

	def get_name(self):
		return self.name

	def get_language(self, source):
		return source.lang
		
	def get_tokens(self, source):
		return source.tokenize()

	def get_tokens_normalize(self, tokens):
		new_tokens = []
		for token in tokens:
			if token.token_type == TokenType.OPERATOR :
				new_tokens.append(token)
		return new_tokens
                
	def get_size(self, vecfrec):
		"""
		số  tokens
		"""
		size = 0
		for token in vecfrec.keys():
			size += vecfrec[token]
		return size

	def get_similarity(self, source1, source2):
		pass

class OperatorFrequencySimilarity(Similarity):
	"""
		What does this similarity measure?
		operator frequence
	"""
	name = 'similarity_1'
	def get_vecfrec(self, source):

		tokens = self.get_tokens(source)
		tokens = self.get_tokens_normalize(tokens)
		vecfrec = {}
		for token in tokens:
			if token.token_value in vecfrec.keys():
				vecfrec[token.token_value] += 1
			else:
				vecfrec[token.token_value] = 1
		return vecfrec

	def get_similarity(self, source1, source2):
		if self.get_language(source1) != self.get_language(source2):
			return 0
		vecfrec1 = self.get_vecfrec(source1)
		vecfrec2 = self.get_vecfrec(source2)
		diff1 = 0
		taken = 0
		for key1 in vecfrec1.keys():
			if key1 in vecfrec2.keys():
				if vecfrec1[key1] != vecfrec2[key1]:
					diff1 += 1
				taken += 1
			else:
				diff1 += 1
		diff2 = len(vecfrec2) - taken
		return 100*(1 - ((diff1 + diff2)/ (len(vecfrec1) + len(vecfrec2))))

class OperatorAppearanceSimilarity(Similarity):
	"""
		What does this similarity measure?
		operator appearance
	"""
	name = 'similarity_2'
	def get_vecfrec(self, source):
		tokens = self.get_tokens(source)
		tokens = self.get_tokens_normalize(tokens)
		vecfrec = {}
		for token in tokens:
			if token.token_value in vecfrec.keys():
				vecfrec[token.token_value] += 1
			else:
				vecfrec[token.token_value] = 1
		return vecfrec

	def get_similarity(self, source1, source2):
		if self.get_language(source1) != self.get_language(source2):
			return 0
		vecfrec1 = self.get_vecfrec(source1)
		vecfrec2 = self.get_vecfrec(source2)
		size1 = self.get_size(vecfrec1)
		size2 = self.get_size(vecfrec2)
		diff = 0
		taken = 0
		for key1 in vecfrec1.keys():
			if key1 in vecfrec2.keys():
				diff += abs(vecfrec2[key1] - vecfrec1[key1])
				taken += vecfrec2[key1]
			else:
				diff += vecfrec1[key1]
		diff += size2 - taken
		return 100*(1 - (diff/(size1+size2)))


class HashedOperatorSimilarity(Similarity):
	"""
		What does this similarity measure?
	"""
	name = 'similarity_3'
	def get_hash(self, source):
		hashes = {}
		tokens = self.get_tokens(source)
		last = ['', '', '', '']
		for token in tokens:
			if token.token_type == TokenType.OPERATOR:
				for i in range(len(last)-1):
					last[i] = last[i+1]
				last[-1] = token.token_value
				item = ''
				for i in range(len(last)):
					item += last[i]
				has = int(hashlib.sha256(item.encode('utf-8')).hexdigest(), 16) % 10**3
				if has in hashes.keys():
					hashes[has] += 1
				else:
					hashes[has] = 1
		return hashes

	def get_similarity(self, source1, source2):
		if self.get_language(source1) != self.get_language(source2):
					return 0
		hashes1 = self.get_hash(source1)
		hashes2 = self.get_hash(source2)
		size1 = self.get_size(hashes1)
		size2 = self.get_size(hashes2)
		diff = 0
		taken = 0
		for key1 in hashes1.keys():
			if key1 in hashes2.keys():
				diff += abs(hashes2[key1] - hashes1[key1])
				taken += hashes2[key1]
			else:
				diff += hashes1[key1]
		diff += size2 - taken
		return 100*(1-(diff/ (size1 + size2)))

all_similarities = [
	OperatorFrequencySimilarity(),
	OperatorAppearanceSimilarity(),
	HashedOperatorSimilarity()
]
