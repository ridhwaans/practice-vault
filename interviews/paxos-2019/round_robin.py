'''
Implement a robin robin iterator in Python which takes in a list of lists and has:
hasNext() to return boolean if there is a next element
next() to return/print the next element

The round robin iterator iterates irrespective of if every list is not the same size
'''
#!/usr/bin/env python2.7
from collections import deque

class RRobin(object):
    def __init__(self, lists):
        self.lists = lists
        self.dq = deque([[i, 0] for i in range(len(lists))])
    
    def hasNext(self):
        return bool(self.dq)
    
    def next(self):
        cur_list, cur_idx = self.dq.popleft()
        if cur_idx + 1 != len(self.lists[cur_list]):
            self.dq.append([cur_list, cur_idx + 1])
        return self.lists[cur_list][cur_idx]

a = ['a1','a2','a3']
b = ['b1']
c = ['c1','c2','c3','c4']
round_robin = RRobin([a,b,c])

while round_robin.hasNext():
	print round_robin.next(),

'''
Time complexity is O(n)
'''