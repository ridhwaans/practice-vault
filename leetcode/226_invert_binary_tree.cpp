#include <queue>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    queue<TreeNode *> q;

    TreeNode *inverted = root;
    q.push(inverted);
    while (!q.empty()) {
      for (int i = 0; i < q.size(); i++) {
        TreeNode *node = q.front();
        q.pop();
        if (!node)
          continue;

        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *tmp = left;
        // mistake - swapped local variables, not actual tree pointers
        // left = right;
        // right = tmp;
        node->left = right;
        node->right = tmp;

        if (left) {
          q.push(left);
        }
        if (right) {
          q.push(right);
        }
      }
    }
    return inverted;
  }
};
