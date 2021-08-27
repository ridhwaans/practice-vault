'''
A node has an integer payload, next pointer and random pointer to another random linked list node. 
Given a singly linked list of such nodes, make a deep copy  
'''
# Input: head = [A[7,null],B[13,0],C[11,4],D[10,2],E[1,0]]
# Expected: [A'[7,null],B'[13,0],C'[11,4],D'[10,2],E'[1,0]]

from collections import defaultdict
class RandomListNode:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random

class Solution:
# @param head, a RandomListNode
# @return a RandomListNode
def copyRandomList(self, head):
    dic = collections.defaultdict(lambda: RandomListNode(0))
    dic[None] = None
    n = head
    while n:
        dic[n].value = n.value
        dic[n].next = dic[n.next]
        dic[n].random = dic[n.random]
        n = n.next
    return dic[head]

'''
Time complexity: O(n)
Space complexity: O(n)
See also:
https://leetcode.com/problems/copy-list-with-random-pointer/
'''