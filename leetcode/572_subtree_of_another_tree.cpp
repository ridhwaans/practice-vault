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
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  bool validate(TreeNode *reference, TreeNode *cur) {
    if (!reference && !cur)
      return true;
    if (!reference || !cur)
      return false;
    if (reference->val != cur->val)
      return false;
    // mistake - did not return the recursive results
    return validate(reference->left, cur->left) &&
           validate(reference->right, cur->right);
    // mistake - tail return not needed and moved
    // return true;
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root || !subRoot)
      return false;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *reference = q.front();
        q.pop();
        if (!reference)
          continue; // use continue not break
        // find matching root
        if (reference->val == subRoot->val) {
          // validate subtree of another tree
          // mistake - dont return on first matching root which may not
          // necessarily yield matching subtree, try all matches
          if (validate(reference, subRoot))
            return true;
        }
        q.push(reference->left);
        q.push(reference->right);
      }
    }
    return false;
  }
};
