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

    def serialize(self, root):
        self.vals = []
        def encode(node):
            if node:
                self.vals.append(str(node.val))
                encode(node.left)
                encode(node.right)
            else:
                self.vals.append('#')
        encode(root)
        return ' '.join(self.vals)

    def deserialize(self, data):
        def decode(vals):
            val = next(vals)
            if val == '#':
                return None
            node = Node(int(val))
            node.left = decode(vals)
            node.right = decode(vals)
            return node
        vals = iter(data.split())
        return decode(vals)

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
