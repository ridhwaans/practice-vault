""""
Given a stream of characters, find the earliest unique character
example: a b c a
a
a
a
b
"""
import sys

def earliest_unique(characters = []):
    is_unique = {} # bookkeeping characters to their indices
    for i, c in enumerate(characters):
        if c not in is_unique.keys():
            is_unique[c] = i # store first occurrence of character
        else:
            is_unique[c] = -1 # one more than occurrence, invalidate character

    min = ('',sys.maxint)
    for ci in is_unique.items():
        if (ci[1] != -1 and ci[1] < min[1]): # select unique characters only
            min = ci
    return -1 if min[1] == sys.maxint else min[0]

test_cases = [['a','b','c','a'],['t','e','n','e','t']]
for case in test_cases:
    print 'Answer is {}'.format(earliest_unique(case))
