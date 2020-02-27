'''
def jobOffers(scores, lowerLimits, upperLimits):

Inputs:
scores = [1,3,5,6,8]
lowerLimits = [2]
upperLimits = [6]
Output:[3]

Inputs:
scores = [4,8,7]
lowerLimits = [2,4]
upperLimits = [8,4]
Output: [3,1]
'''
'''
Assumptions:
scores, lowerLimits, upperLimits are lists of integers
'''
import pytest

def jobOffers(scores, lowerLimits, upperLimits):
    if len(lowerLimits) != len(upperLimits):
        throws("Number of lower and upper limits not equal")
    intervals = []
    for i in range(len(lowerLimits)):
        intervals.append([lowerLimits[i], upperLimits[i]])
        
    result = []
    for interval in intervals:
        result.append(sum([(score >= interval[0]) & (score <= interval[1]) for score in scores]))

    return result

# python -m pytest <python_test>.py
def test_01():
    assert jobOffers([1,3,5,6,8],[2],[6]) == [3]
def test_02():
    assert jobOffers([4,8,7],[2,4],[8,4]) == [3,1]