/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstring>
#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Codec {
public:
  string serialized;

  void removeTrailingNulls() {
    while (!serialized.empty()) {
      // remove trailing commas
      if (!serialized.empty() && serialized.back() == ',') {
        serialized.pop_back();
        continue;
      }

      // remove trailing "null"
      if (serialized.size() >= 4 &&
          serialized.substr(serialized.size() - 4) == "null") {
        serialized.erase(serialized.size() - 4);
        continue;
      }

      break;
    }
  }

  void lvlOrder(TreeNode *node) {
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node == NULL) {
          serialized += "null";
        } else {
          serialized += to_string(node->val);
        }
        serialized += ",";

        if (node != NULL)
          q.push(node->left);
        if (node != NULL)
          q.push(node->right);
      }
    }
  }

  TreeNode *lvlOrderTree(vector<optional<int>> &ls) {
    if (ls.empty() || !ls[0].has_value())
      return NULL;

    TreeNode *root = new TreeNode(ls[0].value());
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < ls.size()) {
      TreeNode *parent = q.front();
      q.pop();

      // left child
      if (i < ls.size() && ls[i].has_value()) {
        parent->left = new TreeNode(ls[i].value());
        q.push(parent->left);
      }
      i++;

      // right child
      if (i < ls.size() && ls[i].has_value()) {
        parent->right = new TreeNode(ls[i].value());
        q.push(parent->right);
      }
      i++;
    }

    return root;
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    serialized = "[";
    lvlOrder(root);
    removeTrailingNulls();
    serialized += "]";
    cout << serialized << endl;
    return serialized;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int size = data.size();
    vector<optional<int>> ls;
    for (int i = 0; i < size; i++) {
      string item = "";
      while (i < size && data[i] != '[' && data[i] != ',' && data[i] != ']') {
        item += data[i];
        i++;
      }
      if (item == "null") {
        // mistake - not nullptr, use nullopt
        ls.push_back(nullopt);
      }
      // condition mistake - terminate called after throwing an instance of
      // 'std::invalid_argument' what():  stoi
      //} else {
      else if (item != "") {
        ls.push_back(stoi(item));
      }
    }

    for (auto x : ls) {
      // error: invalid operands to binary expression cout optional
      // cout << x << endl;
      if (x.has_value()) {
        cout << x.value() << endl;
      } else {
        cout << "null" << endl;
      }
    }

    return lvlOrderTree(ls);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
