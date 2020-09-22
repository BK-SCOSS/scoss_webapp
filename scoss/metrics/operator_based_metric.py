# -*- coding: utf-8 -*-
"""
    code-similarity.operator_based_metric
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    DESCRIPTION
    The algorithms on this file are strongly inspired by Similarity System of Virtual Programming Lab (Moodle)

    :copyright: (c) 2020 by Ngoc Bui.
    :license: MIT LICENSE, see LICENSE for more details.
"""

from __future__ import absolute_import

from scoss.metrics.metric import Metric
from scoss.metrics.token_based_metric import TokenBasedMetric
from sctokenizer.token import TokenType

from abc import ABC, abstractmethod
import hashlib


class OperatorBasedMetric(ABC, TokenBasedMetric):
    OPENNING_BRACKET = "([{"

    def normalize_tokens(self, tokens):
        """get_tokens_normalize.
            only keep tokens are operator or special symbol

        Args:
            tokens:
        """
        new_tokens = []
        for token in tokens:
            if token.token_value in self.OPENNING_BRACKET:
                continue
            if token.token_type == TokenType.OPERATOR or \
                    token.token_type == TokenType.SPECIAL_SYMBOL:
                new_tokens.append(token)
        return new_tokens

    def get_size(self, vecfrec):
        """
        get number of tokens
        """
        size = 0
        for token in vecfrec.keys():
            size += vecfrec[token]
        return size

    def get_vecfrec(self, tokens):
        vecfrec = {}
        for token in tokens:
            if token.token_value in vecfrec.keys():
                vecfrec[token.token_value] += 1
            else:
                vecfrec[token.token_value] = 1
        return vecfrec

    def line_diff(self, line1, line2):
        score = super(OperatorBasedMetric, self).line_diff(line1, line2)
        if score == 1.0:
            return score
        else:
            line1 = self.normalize_tokens(line1)
            line2 = self.normalize_tokens(line2)
            return 0.5 * self.is_equal_tokens(line1, line2)

    @abstractmethod
    def evaluate(self, source1, source2):
        pass


class CountOperator(OperatorBasedMetric):
    """CountOperator.
    """

    name = 'count_operator'

    def evaluate(self, source1, source2):
        if source1.lang != source2.lang:
            raise ValueError(
                'source1 and source2 is written on different language')
        tokens1 = source1.tokenize()
        tokens2 = source2.tokenize()
        tokens1 = self.normalize_tokens(tokens1)
        tokens2 = self.normalize_tokens(tokens2)
        vecfrec1 = self.get_vecfrec(tokens1)
        vecfrec2 = self.get_vecfrec(tokens2)
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
        return (1 - ((diff1 + diff2) / (len(vecfrec1) + len(vecfrec2))))



class SetOperator(OperatorBasedMetric):
    """SetOperator.
    """

    name = 'set_operator'

    def evaluate(self, source1, source2):
        if source1.lang != source2.lang:
            raise ValueError(
                'source1 and source2 is written on different language')
        tokens1 = source1.tokenize()
        tokens2 = source2.tokenize()
        tokens1 = self.normalize_tokens(tokens1)
        tokens2 = self.normalize_tokens(tokens2)
        vecfrec1 = self.get_vecfrec(tokens1)
        vecfrec2 = self.get_vecfrec(tokens2)
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
        return (1 - (diff/(size1+size2)))

class HashOperator(OperatorBasedMetric):
    """HashOperator.

    """

    name = 'hash_operator'

    def get_hash(self, tokens):
        hashes = {}

        last = ['', '', '', '']
        for token in tokens:
            for i in range(len(last)-1):
                last[i] = last[i+1]
            last[-1] = token.token_value
            item = ''
            for i in range(len(last)):
                item += last[i]
            has = int(hashlib.sha256(item.encode(
                'utf-8')).hexdigest(), 16) % 10**3
            if has in hashes.keys():
                hashes[has] += 1
            else:
                hashes[has] = 1
        return hashes

    def evaluate(self, source1, source2):
        if source1.lang != source2.lang:
            raise ValueError(
                'source1 and source2 is written on different language')
        tokens1 = source1.tokenize()
        tokens2 = source2.tokenize()
        tokens1 = self.normalize_tokens(tokens1)
        tokens2 = self.normalize_tokens(tokens2)
        hashes1 = self.get_hash(tokens1)
        hashes2 = self.get_hash(tokens2)
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
        return (1-(diff / (size1 + size2)))

