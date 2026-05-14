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
#include <limits.h> // old C style valid, <climits> valid <climits.h> invalid
#include <string>

using namespace std;

class Solution {
public:
  // mistake - old approach compared a node with its parent, but a BST node must
  // fit within a full valid range from all ancestors mistake #2 - setting high
  // min and low min and updating them with each node fits tracking min/max seen
  // so far, not validating allowed bounds. reverse mistake #3 - returning early
  // when node is valid prevents recursing deeper. fix is to change condition to
  // return early only when node is invalid. skip return true condition keep
  // return false condition mistake #4 - not updating the bounds in next call
  // (climits macro constants initially, new min and new max will get
  // monotonically bigger and smaller) enhancement - parent and side params not
  // needed. dfs calls decide allowed range
  bool dfs(TreeNode *cur, TreeNode *parent, string side, long long minVal,
           long long maxVal) {
    // if (side == "root") return true; // skips recursion and returns true
    if (!cur)
      return true;

    if (side == "right") {
      // C++ automatically promotes long long to int for comparison
      if (!(cur->val > parent->val && cur->val < maxVal)) {
        // invalid right child
        return false;
      }
    }
    if (side == "left") {
      if (!(cur->val < parent->val && cur->val > minVal)) {
        // invalid right child
        return false;
      }
    }
    // everything in left must less than cur, so dont touch minVal for left
    // call. similar for rightside
    return dfs(cur->left, cur, "left", minVal, cur->val) &&
           dfs(cur->right, cur, "right", cur->val, maxVal);
  }

  bool isValidBST(TreeNode *root) {
    if (root == NULL)
      return false;
    return dfs(root, NULL, "root", LLONG_MIN, LLONG_MAX);
  }
};
