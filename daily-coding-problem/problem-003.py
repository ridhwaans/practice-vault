"""
Daily Coding Problem: Problem #3

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
"""

DELIMITER = ','
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

'''
@params: tree (root node)
@return: string
'''
def serialize(node):
    answer = ''
    return preorder_traversal(answer,node)[1:] # remove first character from beginning of string

'''
@params: string
@return: tree (root node)
'''
def deserialize(tree_string):
    tree_list = tree_string.split(DELIMITER)
    node = rebuild(None, tree_list)
    return node

def preorder_traversal(answer, node):
    # Root Left Right
    if node is None:
        answer = answer + DELIMITER + 'None'
    else:
        answer = answer + DELIMITER + node.val
        answer = preorder_traversal(answer, node.left)
        answer = preorder_traversal(answer, node.right)
    return answer

def rebuild(node, tree_list):
    if len(tree_list) != 0:
        value = tree_list.pop(0) # gets first element in list
        if value != 'None':
            node = Node(value)
            node.left = rebuild(node, tree_list)
            node.right = rebuild(node, tree_list)
        else:
            node = Node(None)
    return node

node = Node('root', Node('left', Node('left.left')), Node('right'))
print serialize(node)
assert deserialize(serialize(node)).left.left.val == 'left.left'

'''
Time complexity is O(n)
Space complexity is O(n)

See also:
https://gist.github.com/BiruLyu/8d314ef55539176646476da3c7d3309c
'''
