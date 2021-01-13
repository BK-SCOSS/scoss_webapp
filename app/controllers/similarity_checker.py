import time
import requests
from scoss import Scoss
from scoss import smoss
from scoss.metrics import all_metrics
from sctokenizer import Source
from models.models import Status
import config

all_scoss_metric_names = [metric.get_name() for metric in all_metrics]

def flatten_dict(alignment_list):
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

def cal_scoss(sources, metrics):
    scosses = {}

    for source in sources:
        lang = source['lang']
        if lang not in scosses:
            scoss = Scoss(lang=lang)
            for metric in metrics:
                scoss.add_metric(metric['name'], metric['threshold'])
            scosses[lang] = scoss

        mask = source['mask'] if source['mask'] != '' else source['pathfile']
        scosses[lang].add_source_str(source['source_str'], mask)

    matches = []
    for lang, scoss in scosses.items():
        scoss.run()
        sc_matches = scoss.get_matches(and_thresholds=True)
        matches.extend(sc_matches)
    return matches

def cal_smoss(sources, metrics):
    smosses = {}

    for source in sources:
        lang = source['lang']
        if lang not in smosses:
            smoss = smoss.SMoss(lang=lang)
            for metric in metrics:
                smoss.add_metric(metric['name'], metric['threshold'])
            smosses[lang] = smoss

        mask = source['mask'] if source['mask'] != '' else source['pathfile']
        smosses[lang].add_source_str(source['source_str'], mask)

    matches = []
    comparisons = []
    for lang, smoss in smosses.items():
        smoss.run()
        sm_matches = smoss.get_matches()
        sm_comparisons = flatten_dict(smoss.get_matches_file())
        matches.extend(sm_matches)
        comparisons.extend(sm_comparisons)
    return matches, comparisons

def run_problem(problem_id):
    print("Running problem ", problem_id)
    url = "{}/api/problems/{}".format(config.API_URI_SR, str(problem_id))
    url_status = "{}/api/problems/{}/status".format(config.API_URI_SR, str(problem_id))
    url_scoss = "{}/api/problems/{}/results/scoss".format(config.API_URI_SR, str(problem_id))
    url_smoss = "{}/api/problems/{}/results/smoss".format(config.API_URI_SR, str(problem_id))

    req = requests.get(url)
    data_problem = req.json()

    req_status = requests.get(url=url_status)
        
    doc_status = {
        "problem_status": Status.running
    }
    requests.put(url=url_status, json=doc_status)

    metric_list = []
    scoss_metrics = []
    for met in data_problem['metrics']:
        metric_list.append(met['name'])
        if met['name'] in all_scoss_metric_names:
            scoss_metrics.append(met)

    # run scoss
    if len(scoss_metrics) > 0:
        similarity_list = cal_scoss(data_problem['sources'], scoss_metrics)
    else:
        similarity_list = []
    doc_scoss = {
        "similarity_list": similarity_list,
        "alignment_list": []
    }
    req = requests.put(url=url_scoss, json=doc_scoss)

    # run smoss
    if 'moss_score' in metric_list:
        similarity_smoss_list, alignment_smoss_list = cal_smoss(data_problem['sources'], data_problem['metrics'])
    else:
        similarity_smoss_list, alignment_smoss_list = [], []
    doc_smoss = {
        "similarity_smoss_list": similarity_smoss_list,
        "alignment_smoss_list": alignment_smoss_list
    }
    requests.put(url=url_smoss, json=doc_smoss)

    # update status
    doc_status = {
        "problem_status": Status.checked
    }
    requests.put(url=url_status, json=doc_status)       
    requests.get(url="{}/api/contests/check_status".format(config.API_URI_SR))
