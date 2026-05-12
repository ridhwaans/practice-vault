#include <algorithm>
#include <climits>
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
using namespace std;

class Solution {
public:
  // mistake - making pathSum by reference(&) makes a copy
  int dfs(TreeNode *node, int &pathSum) {
    if (node == NULL)
      return 0;

    int leftPath = dfs(node->left, pathSum);
    int rightPath = dfs(node->right, pathSum);
    leftPath = max(leftPath, 0);
    rightPath = max(rightPath, 0);

    // without split
    pathSum = max(pathSum, node->val + leftPath + rightPath);

    // pick a path (with split)
    return node->val + max(leftPath, rightPath);
  }

  int maxPathSum(TreeNode *root) {
    int pathSum = INT_MIN; // edge case root = [-3] fails if intial pathSum is 0
    // mistake - returning dfs value, not pathSum global variable which tracks
    // the real max. thought int return type meant it needed to return
    dfs(root, pathSum);
    return pathSum;
  }
};
