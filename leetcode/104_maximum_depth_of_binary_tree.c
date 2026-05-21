/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int f(struct TreeNode *node, int depth) {
  if (node == NULL)
    return depth;

  int l = f(node->left, depth + 1);
  int r = f(node->right, depth + 1);

  return (l > r) ? l : r;
}

int maxDepth(struct TreeNode *root) { return f(root, 0); }
