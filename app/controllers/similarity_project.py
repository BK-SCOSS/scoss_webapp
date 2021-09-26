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



def run_project_with_timeout(project_id, timeout=510):
    # @timeout_decorator.timeout(timeout, use_signals=False, timeout_exception=StopIteration)
    def run_project(project_id, _timeout):
        logs = {'str': '', 'exception': []}
        logs['str'] += f"Running project {project_id}\n"
        url = "{}/api/project/{}".format(config.API_URI_SR, str(project_id))
        url_status = "{}/api/project/{}/status".format(config.API_URI_SR, str(project_id))
        url_result= "{}/api/project/{}/results".format(config.API_URI_SR, str(project_id))

        req = requests.get(url)
        data_project = req.json()
        doc_status = {
            "project_status": Status.running
        }
        requests.put(url=url_status, json=doc_status )

        metric_list = []
        scoss_metrics = []
        smoss_metrics = []
        for met in data_project['metrics']:
            metric_list.append(met['name'])
            if met['name'] in all_scoss_metric_names:
                scoss_metrics.append(met)
            elif met['name'] == 'moss_score':
                smoss_metrics.append(met)

        # run scoss
        logs['str'] += f"Running..."
        if scoss_metrics and smoss_metrics:
            scoss_similarity_dict = cal_scoss(data_project['sources'], scoss_metrics)
            smoss_similarity_dict = cal_smoss(data_project['sources'], smoss_metrics)
            for key in list(scoss_similarity_dict):
                if key in smoss_similarity_dict:
                    scoss_similarity_dict[key]['smoss_alignment'] = smoss_similarity_dict[key]['smoss_alignment']
                    for metric in list(smoss_similarity_dict[key]['scores']):
                        scoss_similarity_dict[key]['scores'][metric] = smoss_similarity_dict[key]['scores'][metric]
            similarity_dict = scoss_similarity_dict
        elif scoss_metrics:
            similarity_dict = cal_scoss(data_project['sources'], scoss_metrics)
        elif smoss_metrics:
            similarity_dict = cal_smoss(data_project['sources'], smoss_metrics)
        requests.put(url=url_result, json={'result_list':list(similarity_dict.values())})
        # update status
        doc_status = {
            "project_status": Status.checked
        }
        requests.put(url=url_status, json=doc_status)       
        # requests.get(url="{}/api/contests/{}/check_status".format(config.API_URI_SR, contest_id))
        return logs
    return run_project(project_id,_timeout=timeout-5)

def do_project(project_id, timeout=510):
    def update_status_failed(project_id):
        url_status = "{}/api/project/{}/status".format(config.API_URI_SR, str(project_id))
        # update status
        doc_status = {
            "project_status": Status.failed
        }
        requests.put(url=url_status, json=doc_status)       
    try:
        logs = run_project_with_timeout(project_id, timeout)
        if len(logs['exception']) > 0:
            update_status_failed(project_id)
            raise Exception
    except Exception as e:
        update_status_failed(project_id)
        raise e