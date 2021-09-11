import time
import requests
from scoss import Scoss
from scoss import SMoss
from scoss.metrics import all_metrics
from sctokenizer import Source
from models.models import Status
import config
import timeout_decorator

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
            smoss = SMoss(lang=lang)
            smoss.set_threshold(metrics[0]['threshold'])
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


def run_problem_with_timeout(problem_id, header, timeout=510):
    # @timeout_decorator.timeout(timeout, use_signals=False, timeout_exception=StopIteration)
    def run_problem(problem_id, header, _timeout):
        logs = {'str': '', 'exception': []}
        logs['str'] += f"Running problem {problem_id}\n"
        url = "{}/api/problems/{}".format(config.API_URI_SR, str(problem_id))
        url_status = "{}/api/problems/{}/status".format(config.API_URI_SR, str(problem_id))
        url_scoss = "{}/api/problems/{}/results/scoss".format(config.API_URI_SR, str(problem_id))
        url_smoss = "{}/api/problems/{}/results/smoss".format(config.API_URI_SR, str(problem_id))

        req = requests.get(url, headers={'Authorization': header})
        data_problem = req.json()
        # contest_id = data_problem['contest_id']

        # req_status = requests.get(url=url_status, headers={'Authorization': header})
            
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

        # run scoss
        logs['str'] += f"Running scoss\n"
        if scoss_metrics:
            similarity_list = cal_scoss(data_problem['sources'], scoss_metrics)
        else:
            similarity_list = []
        logs['str'] += "Done scoss\n"

        doc_scoss = {
            "similarity_list": similarity_list,
            "alignment_list": []
        }
        req = requests.put(url=url_scoss, json=doc_scoss, headers={'Authorization': header})
        # run smoss
        logs['str'] += f"Running smoss\n"
        if smoss_metrics:
            similarity_smoss_list, alignment_smoss_list = cal_smoss(data_problem['sources'], smoss_metrics)
        else:
            similarity_smoss_list, alignment_smoss_list = [], []
        logs['str'] += "Done smoss\n"

        doc_smoss = {
            "similarity_smoss_list": similarity_smoss_list,
            "alignment_smoss_list": alignment_smoss_list
        }
        requests.put(url=url_smoss, json=doc_smoss, headers={'Authorization': header})

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
        if len(logs['exception']) > 0:
            update_status_failed(problem_id, header)
            raise Exception
    except Exception as e:
        update_status_failed(problem_id, header)
        raise e
