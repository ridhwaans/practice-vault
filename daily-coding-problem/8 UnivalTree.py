'''
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1	
'''

class Node():
	def __init__(self, val):
		self.val = val
		self.right = None
		self.left = None

def is_unival(node):
	if node is None:
		return True
	if node.left is not None and node.left.val != node.val:
		return False
	if node.right is not None and node.right.val != node.val:
		return False
	if is_unival(node.left) and is_unival(node.right):
		# a node with no children also counts as unival
		return True
	return False

def count_univals(node):
	if node is None:
		return 0
	total_count = count_univals(node.left) + count_univals(node.right)
	if is_unival(node):
		total_count += 1
	return total_count


tree = Node(0)
tree.left = Node(1)
tree.right = Node(0)
tree.right.left = Node(1)
tree.right.right = Node(0)
tree.right.left.left = Node(1)
tree.right.left.right = Node(1)

print "The answer is {}".format(count_univals(tree))
