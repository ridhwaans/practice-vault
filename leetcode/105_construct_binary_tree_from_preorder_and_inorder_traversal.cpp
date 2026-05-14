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
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
      return NULL;

    TreeNode *root = new TreeNode(preorder[0]);
    // error: non-const lvalue reference to type 'vector<int>' cannot bind to a
    // temporary of type 'iterator' Compile error because erase() returns an
    // iterator, not a vector. lacking a mid root->left =
    // buildTree(preorder.erase(preorder.begin()),
    // inorder.erase(inorder.begin()+1));

    // offset while mid is found
    // mid is not necessarily 2nd elem when tree can be of variable size
    int offset = 0;
    // mistake - did not check against inorder
    // while (preorder[0] != preorder[offset]){
    // optional out of bounds check offset < inorder.size()
    while (root->val != inorder[offset]) {
      offset++;
    }

    // mistake - not slicing vectors correctly
    // only erased one element, not everything after the left subtree. Also it
    // keeps the root in leftPre, which is wrong

    // left preorder: remove root, then remove right subtree
    vector<int> leftPre = preorder;
    leftPre.erase(leftPre.begin());
    leftPre.erase(leftPre.begin() + offset, leftPre.end());

    // left inorder: remove root + right subtree
    vector<int> leftIn = inorder;
    leftIn.erase(leftIn.begin() + offset, leftIn.end());

    // right preorder: remove root + left subtree
    vector<int> rightPre = preorder;
    rightPre.erase(rightPre.begin(), rightPre.begin() + 1 + offset);

    // right inorder: remove left subtree + root
    vector<int> rightIn = inorder;
    rightIn.erase(rightIn.begin(), rightIn.begin() + 1 + offset);

    root->left = buildTree(leftPre, leftIn);
    root->right = buildTree(rightPre, rightIn);

    // mistake - TreeNode root = newTreeNode(preorder[0]); return *root; is
    // incorrect
    return root;
  }
};
