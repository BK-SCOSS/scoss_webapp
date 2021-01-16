from collections import defaultdict
import sys

def longestSubsequence(a, n):
    mp = defaultdict(lambda:0)
 
    dp = [0 for i in range(n)]
    maximum = -1
 
    # iterate for all element 
    for i in range(n):
 
        if a[i] - 1 not in mp:
 
            dp[i] = 1
        else:
            lastIndex = mp[a[i] - 1] - 1
            dp[i] = 1 + dp[lastIndex]

        mp[a[i]] = i + 1
 
        maximum = max(maximum, dp[i])
    return maximum
 
 
t = int(input())
for i in range(t):
    n = int(input())

    arr = [int(i) for i in input()[:-1].split(' ')]
    print(longestSubsequence(arr, n))