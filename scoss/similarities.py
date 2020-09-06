from __future__ import absolute_import

class Similarity():
	__name = None
	def __init__(self):
		pass

	@staticmethod
	def get_name():
		return Similarity.__name

	def judge(self, source1, source2):
		pass

class OperatorSimilarity(Similarity):
	"""
		What does this similarity measure?
	"""
	__name = 'operator'
	def judge(self, source1, source2):
		pass

class HashedOperatorSimilarity(Similarity):
	"""
		What does this similarity measure?
	"""
	__name = 'hashed_operator'
	pass


all_similarities = [
	OperatorSimilarity(),
	HashedOperatorSimilarity()
]