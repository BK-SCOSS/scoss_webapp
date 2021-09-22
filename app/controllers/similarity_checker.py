import time
import requests
from scoss import Scoss
from scoss import SMoss
from scoss.metrics import all_metrics
from sctokenizer import Source
from models.models import *
import config
import timeout_decorator
from jinja2 import Environment

# from random import randint

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
    return list(match_dict.values())

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

    scoss_similarity_dict = {}
    for lang, scoss in scosses.items():
        scoss.run()
        sc_matches = scoss.get_matches(and_thresholds=True)
        for sc_match in sc_matches:
            if sc_match['source1'] > sc_match['source2']:
                key = sc_match['source2'] + '_' + sc_match['source1']
            else:
                key = sc_match['source1'] + '_' + sc_match['source2']

            scoss_similarity_dict[key] = sc_match
            scoss_similarity_dict[key]['smoss_alignment'] = ''
    return scoss_similarity_dict

def cal_smoss(sources, metrics):
    smosses = {}
    for source in sources:
        lang = source['lang']
        if lang not in smosses:
            smoss = SMoss(lang=lang)
            # smoss = SMoss(lang=lang, userid=randint(20000, 90000))
            smoss.set_threshold(metrics[0]['threshold'])
            smosses[lang] = smoss

        mask = source['mask'] if source['mask'] != '' else source['pathfile']
        smosses[lang].add_source_str(source['source_str'], mask)

    smoss_similarity_dict = {}
    for lang, smoss in smosses.items():
        smoss.run()
        sm_matches = smoss.get_matches()
        sm_comparisons = flatten_dict(smoss.get_matches_file())
        for i, sm_match in enumerate(sm_matches):
            if sm_match['source1'] > sm_match['source2']:
                key = sm_match['source2'] + '_' + sm_match['source1']
            else:
                key = sm_match['source1'] + '_' + sm_match['source2']

            smoss_similarity_dict[key] = sm_match
            smoss_similarity_dict[key]['smoss_alignment'] = sm_comparisons[i]['scores']
    return smoss_similarity_dict

def run_problem_with_timeout(problem_id, header, timeout=510):
    # @timeout_decorator.timeout(timeout, use_signals=False, timeout_exception=StopIteration)
    def run_problem(problem_id, header, _timeout):
        logs = {'str': '', 'exception': []}
        logs['str'] += f"Running problem {problem_id}\n"
        url = "{}/api/problems/{}".format(config.API_URI_SR, str(problem_id))
        url_result = "{}/api/problems/{}/results".format(config.API_URI_SR, str(problem_id))
        url_status = "{}/api/problems/{}/status".format(config.API_URI_SR, str(problem_id))

        req = requests.get(url, headers={'Authorization': header})
        data_problem = req.json()
            
        doc_status = {
            "problem_status": Status.running
        }
        requests.put(url=url_status, json=doc_status, headers={'Authorization': header})

        metric_list = []
        scoss_metrics = []
        smoss_metrics = []
        for met in data_problem['metrics']:
            metric_list.append(met['name'])
            if met['name'] in all_scoss_metric_names:
                scoss_metrics.append(met)
            elif met['name'] == 'moss_score':
                smoss_metrics.append(met)

        logs['str'] += f"Running..."
        if scoss_metrics and smoss_metrics:
            scoss_similarity_dict = cal_scoss(data_problem['sources'], scoss_metrics)
            smoss_similarity_dict = cal_smoss(data_problem['sources'], smoss_metrics)
            for key in list(scoss_similarity_dict):
                if key in smoss_similarity_dict:
                    scoss_similarity_dict[key]['smoss_alignment'] = smoss_similarity_dict[key]['smoss_alignment']
                    for metric in list(smoss_similarity_dict[key]['scores']):
                        scoss_similarity_dict[key]['scores'][metric] = smoss_similarity_dict[key]['scores'][metric]
            similarity_dict = scoss_similarity_dict
        elif scoss_metrics:
            similarity_dict = cal_scoss(data_problem['sources'], scoss_metrics)
        elif smoss_metrics:
            similarity_dict = cal_smoss(data_problem['sources'], smoss_metrics)
        requests.put(url=url_result, json={'result_list':list(similarity_dict.values())}, headers={'Authorization': header})
        # update status
        doc_status = {
            "problem_status": Status.checked
        }
        requests.put(url=url_status, json=doc_status, headers={'Authorization': header})       
        # requests.get(url="{}/api/contests/{}/check_status".format(config.API_URI_SR, contest_id))
        return logs
    return run_problem(problem_id, header,_timeout=timeout-5)

def do_job(problem_id, header, timeout=510):
    def update_status_failed(problem_id, header):
        url_status = "{}/api/problems/{}/status".format(config.API_URI_SR, str(problem_id))
        # update status
        doc_status = {
            "problem_status": Status.failed
        }
        requests.put(url=url_status, json=doc_status, headers={'Authorization': header})       
        requests.get(url="{}/api/contests/check_status".format(config.API_URI_SR),\
            headers={'Authorization': header})

    try:
        logs = run_problem_with_timeout(problem_id, header, timeout)
        url_problem_result = "{}/api/problems/{}/results".format(config.API_URI_SR, str(problem_id))
        res = requests.get(url=url_problem_result)
        if(len(res.json()['results']) > 0):
            contest_id = res.json()['contest_id']
            problem_id = res.json()['problem_id']
            problem_name = res.json()['problem_name']
            data = []
            for result in res.json()['results']:
                doc = {
                    "source1": result['source1'],
                    "source2": result['source2'],
                    "scores": result['scores'],
                    "problem_id": problem_id,
                    "problem_name": problem_name
                }
                data.append(doc)
            doc_result = {
                "data": data
            }
            url_problem_result = "{}/api/problems/{}/results".format(config.API_URI_SR, str(problem_id))
            requests.put(url=url_problem_result, json=doc_result)
        if len(logs['exception']) > 0:
            update_status_failed(problem_id, header)
            raise Exception
    except Exception as e:
        update_status_failed(problem_id, header)
        raise e
