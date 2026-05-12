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
#include <queue>
#include <vector>

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == NULL)
      return {};

    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      vector<int> level;
      int size = q.size();
      // mistake - changed i < q.size() to size because it kept changing depth
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
          continue;
        level.push_back(node->val);

        // check prevents empty vectors in answer
        if (node->left != NULL)
          q.push(node->left);
        if (node->right != NULL)
          q.push(node->right);
      }
      res.push_back(level);
    }
    return res;
  }
};
