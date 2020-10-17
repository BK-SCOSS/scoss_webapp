import time
import requests
from config import URL
from scoss import Scoss
from scoss import smoss
from scoss.metrics import all_metrics
from sctokenizer import Source


def cal_scoss(sources, metrics):
	sc = Scoss(lang='cpp')
	sc.add_metric('count_operator', 0.0)
	sc.add_metric('set_operator')
	for source in sources:
		if source['mask'] == '':
			sc.add_source_str(source['source_str'], mask=source['pathfile'])
		else:
			sc.add_source_str(source['source_str'], mask=source['mask'])
	# sc.add_file('./tests/data/c.cpp', mask='Ngoc')
	sc.run()
	print(sc.get_matches())
	# programs = []
	# similarity_list = []
	# alignment_list = []
	# for source in sources:
	# 	lang = source['lang']
	# 	check = False
	# 	for program in programs:
	# 		if program.get_language() == lang:
	# 			check = True
	# 			if source['mask'] == '':
	# 				program.add_source_str(source['source_str'], mask=source['pathfile'])
	# 			else:
	# 				program.add_source_str(source['source_str'], mask=source['mask'])
	# 	if not check:
	# 		sc = Scoss(lang=lang)
	# 		for metric in all_metrics:
	# 			for met in metrics:
	# 				if metric.get_name() == met['name']:
	# 					sc.add_metric(met['name'], met['threshold'])
	# 		if source['mask'] == '':
	# 			sc.add_source_str(source['source_str'], mask=source['pathfile'])
	# 		else:
	# 			sc.add_source_str(source['source_str'], mask=source['mask'])
	# 		programs.append(sc)
	# for program in programs: 
	# 	for matrix in program.get_matches():
	# 		similarity_list.append(matrix)
	# 	for matrix in program.get_alignment_list():
	# 		alignment_list.append(matrix)
	# return similarity_list, alignment_list

def cal_smoss(sources, metrics):
	programs = []
	similarity_list = []
	alignment_list = []
	# for source in sources:
	# 	lang = source['lang']
	# 	if str(lang) == 'cpp':
	# 		lang = 'cc'
	# 	check = False
	# 	for program in programs:
	# 		if str(program.get_language()) == lang:
	# 			check = True
	# 			if source['mask'] == '':
	# 				program.add_source_str(source['source_str'], mask=source['pathfile'])
	# 			else:
	# 				program.add_source_str(source['source_str'], mask=source['mask'])
	# 	if not check:
	# 		sm = smoss.SMoss(lang=lang)
	# 		for met in metrics:
	# 			if met['name'] == 'smoss_metric':
	# 				print(metrics)
	# 				sm.set_threshold(met['threshold'])
	# 		if source['mask'] == '':
	# 			sm.add_source_str(source['source_str'], mask=source['pathfile'])
	# 		else:
	# 			sm.add_source_str(source['source_str'], mask=source['mask'])
	# 		programs.append(sm)
	# for program in programs: 
	# 	program.run()
	# 	for matrix in program.get_matches():
	# 		similarity_list.append(matrix)
	# 	for matrix in convert_matrix(program.get_matches_file()):
	# 		alignment_list.append(matrix)
	return similarity_list, alignment_list

def convert_matrix(alignment_list):
	match_dict = {}
	for name, score_dict in alignment_list.items():
		for other_name, scores in score_dict.items():
			key = hash(name) ^ hash(other_name)
			match = {}
			match['source1'] = name
			match['source2'] = other_name
			match['scores'] = scores
			match_dict[key] = match
	matches_alignment = list(match_dict.values())
	return matches_alignment

def run_problem(problem_id):
    url = URL + '/api/problems/' + str(problem_id)
    req = requests.get(url)
    data_problem = req.json()
    similarity_list, alignment_list = cal_scoss(data_problem['sources'], data_problem['metrics'])
    print(similarity_list, alignment_list)
    # similarity_smoss_list, alignment_smoss_list = cal_smoss(data_problem['sources'], data_problem['metrics'])
