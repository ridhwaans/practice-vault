#include <optional>
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

using namespace std;

class Solution {
public:
  vector<optional<int>> toList(TreeNode *n) {
    vector<optional<int>> ls;
    queue<TreeNode *> bfsQ;
    bfsQ.push(n);

    // reference is not nullable so change TreeNode& to * pointer
    if (n == nullptr)
      return {};

    while (!bfsQ.empty()) {
      int s = bfsQ.size();
      for (int i = 0; i < s; i++) {
        struct TreeNode *node = bfsQ.front(); // this is valid
        bfsQ.pop();

        if (node == NULL) {
          // using -1 as sentinel value for NULL was mistake because it is also
          // a valid tree value and failed some test cases redefined vector as
          // optional<int>
          ls.push_back(nullopt);
          continue;
        }
        ls.push_back(node->val);

        // mistake - not pushing null children into queue
        // since queue takes pointers, include pointers to both real children
        // and null children if (node->left) {
        //      bfsQ.push(node->left);
        // } else {
        //     ls.push_back(-1);
        // }
        bfsQ.push(node->left);
        bfsQ.push(node->right);
      }
    }
    return ls;
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    vector<optional<int>> pList = toList(p);
    vector<optional<int>> qList = toList(q);

    if (pList.size() != qList.size())
      return false;

    for (int i = 0; i < pList.size(); i++) {
      if (pList[i] != qList[i])
        return false;
    }
    return true;
  }
};
