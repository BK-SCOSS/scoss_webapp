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

from scoss.metrics import Metric
from sctokenizer.token import TokenType

import hashlib


class OperatorBasedMetric(Metric):

    def normalize_tokens(self, tokens):
        """get_tokens_normalize.
            only keep tokens are operator or special symbol

        Args:
            tokens:
        """
        new_tokens = []
        for token in tokens:
            # TODO: Remove openning or closing bracket
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

    def get_vecfrec(self, source):
        tokens = source.tokenize()
        tokens = self.normalize_tokens(tokens)
        vecfrec = {}
        for token in tokens:
            if token.token_value in vecfrec.keys():
                vecfrec[token.token_value] += 1
            else:
                vecfrec[token.token_value] = 1
        return vecfrec


class CountOperator(OperatorBasedMetric):
    """CountOperator.
    """

    name = 'count_operator'

    def evaluate(self, source1, source2):
        if source1.lang != source2.lang:
            raise ValueError(
                'source1 and source2 is written on different language')
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
        return 100*(1 - ((diff1 + diff2) / (len(vecfrec1) + len(vecfrec2))))


class SetOperator(OperatorBasedMetric):
    """SetOperator.
    """

    name = 'set_operator'

    def evaluate(self, source1, source2):
        if source1.lang != source2.lang:
            raise ValueError(
                'source1 and source2 is written on different language')
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


class HashOperator(OperatorBasedMetric):
    """HashOperator.

    """

    name = 'hash_operator'

    def get_hash(self, source):
        hashes = {}
        tokens = source.tokenzie()
        tokens = self.normalize_tokens(tokens)

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
        return 100*(1-(diff / (size1 + size2)))
