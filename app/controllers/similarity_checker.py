import time
import requests
from config import URL
from scoss import Scoss
from scoss import smoss
from scoss.metrics import all_metrics
from sctokenizer import Source


def cal_scoss(sources, metrics):
	programs = []
	similarity_list = []
	alignment_list = []
	for source in sources:
		lang = source['lang']
		check = False
		for program in programs:
			if program.get_language() == lang:
				check = True
				if source['mask'] == '':
					program.add_source_str(source['source_str'], mask=source['pathfile'])
				else:
					program.add_source_str(source['source_str'], mask=source['mask'])
		if not check:
			sc = Scoss(lang=lang)
			for metric in all_metrics:
				for met in metrics:
					if metric.get_name() == met['name']:
						sc.add_metric(met['name'], met['threshold'])
			if source['mask'] == '':
				sc.add_source_str(source['source_str'], mask=source['pathfile'])
			else:
				sc.add_source_str(source['source_str'], mask=source['mask'])
			programs.append(sc)
	for program in programs:
		print(program.get_matches(or_thresholds=True)) 
		for matrix in program.get_matches(or_thresholds=True):
			similarity_list.append(matrix)
		for matrix in program.get_aligment_matrix():
			alignment_list.append(matrix)
	return similarity_list, alignment_list

def cal_smoss(sources, metrics):
	programs = []
	similarity_list = []
	alignment_list = []
	for source in sources:
		lang = source['lang']
		if str(lang) == 'cpp':
			lang = 'cc'
		check = False
		for program in programs:
			if str(program.get_language()) == lang:
				check = True
				if source['mask'] == '':
					program.add_source_str(source['source_str'], mask=source['pathfile'])
				else:
					program.add_source_str(source['source_str'], mask=source['mask'])
		if not check:
			sm = smoss.SMoss(lang=lang)
			for met in metrics:
				if met['name'] == 'moss_score':
					sm.set_threshold(met['threshold'])
			if source['mask'] == '':
				sm.add_source_str(source['source_str'], mask=source['pathfile'])
			else:
				sm.add_source_str(source['source_str'], mask=source['mask'])
			programs.append(sm)
	for program in programs: 
		program.run()
		for matrix in program.get_matches():
			similarity_list.append(matrix)
		for matrix in convert_matrix(program.get_matches_file()):
			alignment_list.append(matrix)
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
	url_status = URL + '/api/problems/' + str(problem_id) + '/status'
	url_scoss = URL + '/api/problems/' + str(problem_id) + '/results/scoss'
	url_smoss = URL + '/api/problems/' + str(problem_id) + '/results/smoss'
	req_status = requests.get(url=url_status)
	if req_status.json()['problem_status'] in ['init', 'reopen', 'checked']:
		doc_status = {
			"problem_status": "waiting"
		}
		requests.put(url=url_status, json=doc_status)
		similarity_list, alignment_list = cal_scoss(data_problem['sources'], data_problem['metrics'])
		if len(similarity_list) >= 0 and len(alignment_list) >= 0:
			doc_scoss = {
				"similarity_list": similarity_list,
				"alignment_list": alignment_list
			}
			requests.put(url=url_scoss, json=doc_scoss)
		similarity_smoss_list, alignment_smoss_list = cal_smoss(data_problem['sources'], data_problem['metrics'])
		if len(similarity_smoss_list) >= 0 and len(alignment_smoss_list) >= 0:
			doc_scoss = {
				"similarity_smoss_list": similarity_smoss_list,
				"alignment_smoss_list": alignment_smoss_list
			}
			requests.put(url=url_scoss, json=doc_scoss)
		doc_status = {
			"problem_status": "checked"
		}
		requests.put(url=url_status, json=doc_status)		
