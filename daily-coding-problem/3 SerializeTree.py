"""
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

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def serialize(root):
    s = []
    def serializer(root, output=None):
        if (root is None): return s.append(-1)
        s.append(root.val)
        serializer(root.left)
        serializer(root.right)
    serializer(root,s)
    print s
    return ', '.join(str(item) for item in s)

def deserialize(data):
    s = data.split(',')
    if (len(s) == 0): 
        return None 
    i = 0
    def deserializer(s, i):
        if (i == len(s) or s[i] == int(-1)):
            return None
        node = Node(s[i])

        i += 1
        node.left = deserializer(s, i)
        i += 1
        node.right = deserializer(s, i)
        return node
    return deserializer(s, i)

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'


'''
See also:
https://gist.github.com/BiruLyu/8d314ef55539176646476da3c7d3309c
'''