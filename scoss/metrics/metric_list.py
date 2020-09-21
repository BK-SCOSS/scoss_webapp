from __future__ import absolute_import

from scoss.metrics.operator_based_metric import *

all_metrics = [
    CountOperator(),
    SetOperator(),
    HashOperator()
]


class MetricList():
    def __init__(self, metric_list=None):
        self.metric_list = []
        for metric in metric_list:
            self.add_metric(metric)

    def get_metric_names(self):
        ret = []
        for metric in self.metric_list:
            ret.append(metric.get_name())
        return ret

    def add_metric(self, metric, exist_ok=False):
        if isinstance(metric, Metric):
            for metric in self.metric_list:
                if metric.get_name() == metric.get_name():
                    if exist_ok:
                        return
                    else:
                        raise ValueError(f'the metric {metric.get_name()} already exists in metric_list')
            self.metric_list.append(metric)
        elif isinstance(metric, str):
            self.add_metric_by_name(metric, exist_ok=exist_ok)
        else:
            raise ValueError('Invalid type of metric, only accept Metric or str')

    def add_metric_by_name(self, metric_name, exist_ok=False):
        for metric in self.metric_list:
            if metric.get_name() == metric_name:
                if exist_ok:
                    return
                else:
                    raise ValueError(f'the metric {metric_name} already exists in metric_list')

        for metric in all_metrics:
            if metric.get_name() == metric_name:
                self.metric_list.append(metric)
                return

        raise ValueError(f'Unknown metric_name: {metric_name}')

    def remove_metric_by_name(self, metric_name):
        for metric in all_metrics:
            if metric.get_name() == metric_name:
                self.metric_list.remove(metric)
                return

    def evaluate(self, source1, source2):
        ret = {}
        for metric in self.metric_list:
            ret[metric.get_name()] = metric.evaluate(source1, source2)
        return ret

    def align_source(self, source1, source2):
        ret = {}
        for metric in self.metric_list:
            ret[metric.get_name()] = metric.align_source(source1, source2)

        return ret

     
        
