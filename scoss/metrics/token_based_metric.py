from scoss.metrics.metric import Metric
from sctokenizer import Source
from sctokenizer.token import TokenType

class TokenBasedMetric(Metric):
    name = 'token_based'

    def __init__(self):
        pass

    def get_name(self):
        return self.name

    def normalize_tokens(self, tokens):
        return tokens

    def evaluate(self, source1, source2):
        if source1.lang != source2.lang:
            raise ValueError(
                'source1 and source2 is written on different language')
        tokens1 = source1.tokenize()
        tokens2 = source2.tokenize()
        tokens1 = self.normalize_tokens(tokens1)
        tokens2 = self.normalize_tokens(tokens2)
        if len(tokens1) != len(tokens2):
            return 0.0
        for i in range(len(tokens1)):
            if tokens1[i].token_type != tokens2[i].token_type or \
                    tokens1[i].token_value != tokens2[i].token_value:
                return 0.0
        return 1.0

    def compact_line(self, tokens):
        lines = [[] for _ in range(tokens[-1].line + 1)]
        for token in tokens:
            lines[token.line].append(token)
        return lines

    def is_equal_tokens(self, tokens1, tokens2):
        if len(tokens1) != len(tokens2):
            return 0.0
        for i in range(len(tokens1)):
            if tokens1[i].token_type != tokens2[i].token_type or \
                    tokens1[i].token_value != tokens2[i].token_value:
                return 0.0
        return 1.0

    def line_diff(self, line1, line2):
        return 1 * self.is_equal_tokens(line1, line2)

    def align_source(self, source1, source2):
        tokens1 = source1.tokenize()
        lines1 = self.compact_line(tokens1)
        tokens2 = source2.tokenize()
        lines2 = self.compact_line(tokens2)
        
        n, m = len(lines1), len(lines2)
        
        diff_matrix = [[0]*(m+1) for _ in range(n+1)]
        d = [[0]*(m+1) for _ in range(n+1)]

        for i in range(1, n):
            for j in range(1, m):
                diff_matrix[i][j] = self.line_diff(lines1[i], lines2[j])

        for i in range(n+1):
            d[i][0] = i
        for i in range(m+1):
            d[0][i] = i
    
        for i in range(1, n+1):
            for j in range(1, m+1):
                d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, 
                              d[i-1][j-1] + 1 - diff_matrix[i][j])

        diff = []
        i, j = n, m 
        while i != 0 or j != 0:
            if d[i][j] == d[i-1][j-1] + 1 - diff_matrix[i][j]:
                diff.append( (i, j, diff_matrix[i][j]) )
                i, j = i-1, j-1
            elif d[i][j] == d[i-1][j] + 1:
                diff.append( (i, -1, -1) )
                i, j = i-1, j
            elif d[i][j] == d[i][j-1] + 1:
                diff.append( (-1, j, -1) )
                i, j = i, j-1

        diff.reverse()

        return diff


        