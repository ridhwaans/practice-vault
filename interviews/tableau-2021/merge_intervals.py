'''
Given a list of intervals, merge all overlapping intervals and return a list of non-overlapping intervals

Assumptions:
- can contain negative integers or duplicates
- not necessarily sorted; any order
'''

# [1,5] [6,10] [11,12] [15,17] [32,40]
#   \     /              \       /
#    [4,7]                [16,36]
# expected: [[1,10], [11,12], [15,40]]

def merge(self, intervals):
    out = []
    for i in sorted(intervals, key=lambda i: i.start):
        if out and i.start <= out[-1].end:
            out[-1].end = max(out[-1].end, i.end)
        else:
            out += i,
    return out

'''
See also: 
https://leetcode.com/problems/merge-intervals/
'''