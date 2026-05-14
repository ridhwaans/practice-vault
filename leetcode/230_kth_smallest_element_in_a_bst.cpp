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

/*
mistake - making stack int not stack TreeNode*
mistake #2 - pushing cur->left to stack before pushing cur
mistake #3 while loop is || not &&
mistake #4 runtime error: reference binding to misaligned address for type
'TreeNode *', which requires 8 byte alignment. fix change while (!cur) to while
(cur)
*/
#include <stack>

using namespace std;
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> s;
    TreeNode *cur = root;
    int n = 0;
    while (cur || !s.empty()) {
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }
      cur = s.top();
      s.pop();
      n++;
      // increment before check because there is no such thing as 0th smallest
      // alternatively countdown k to 0
      if (n == k)
        return cur->val;
      cur = cur->right;
    }
    return -1;
  }
};

/*
stop as soon as it reaches kth. h is the tree height
Time:  O(h + k)
Space: O(h)

complete inorder into array
Time:  O(n)
Space: O(n)
*/
