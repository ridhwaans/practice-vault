#include <string>
#include <vector>

using namespace std;

/*
Two designs
root->val holds a character or holds a dummy root (new TrieNode('\0'))
Dummy root means root->val is not part of any word. It is just a starting
container. In a standard trie, root is the only dummy node and every child &
descendant holds one character
*/

// mistake - trie is not necessarily binary
struct TrieNode {
  char val;
  vector<TrieNode *> children;
  // mistake - Trie needed isWord and did not need to hold first letter
  bool isWord;
  // mistake - missed constructor and vector cannot be initialized with nullptr
  // TrieNode(char x) : val(x), children(nullptr) {}
  TrieNode(char x) : val(x), isWord(false) {}
}; // needed semicolon here, constructor didnt need semicolon

class Trie {
private:
  TrieNode *root;

public:
  Trie() : root(new TrieNode('\0')) {}

  void insert(string word) {
    TrieNode *cur = this->root;
    for (char c : word) {
      // mistake - when cur is empty, new changes the pointer, but not root
      // if (!cur) cur = new TrieNode(c);
      if (!cur) {
        this->root = new TrieNode(c);
        cur = this->root;
        // mistake - missed continue otherwise same char gets reprocessed
        continue;
      }
      // mistake - original trie design made root hold the first letter
      // if (i == 0 && cur->val == c) {
      //     continue;
      // }

      // mistake - while repeats the same character forever
      // while (cur){}
      // mistake - break & continue are logically dangerous that skip to next
      // char or skip all chars. only works for the root’s first char, not
      // deeper characters if (cur->val == c) break;
      // mistake - copying children and pushing into it does not update
      // cur->children. should be &
      vector<TrieNode *> &children = cur->children;

      // mistake - dont need push_back here since it is now done after the for
      // loop
      // // mistake - children is vector not a pointer
      // // if (!children)
      // if (children.empty()){
      //     // mistake - children stores pointers, not chars
      //     //children.push_back(c);

      //     // trie children dont have to be sorted
      //     children.push_back(new TrieNode(c));
      //     // mistake - did not move to new child for next char
      //     cur = children.back();
      //     break; // inserted. go next char
      // }
      bool found = false;
      for (auto node : children) {
        if (node->val == c) {
          cur = node;
          // mistake - i missed adding a found bool to prevent duplicate
          // characters in children
          found = true;
          break; // already exists. go next char
        }
      }

      if (!found) {
        children.push_back(new TrieNode(c));
        cur = children.back(); // inserted. move cur for next char
      }
    }
    cur->isWord = true;
  }
  bool search(string word) {
    TrieNode *cur = this->root;

    for (char c : word) {
      TrieNode *next = nullptr;

      for (TrieNode *child : cur->children) {
        if (child->val == c) {
          next = child;
          break;
        }
      }

      if (!next)
        return false;

      cur = next;
    }

    return cur->isWord;
  }

  bool startsWith(string prefix) {
    TrieNode *cur = this->root;

    for (char c : prefix) {
      TrieNode *next = nullptr;

      for (TrieNode *child : cur->children) {
        if (child->val == c) {
          next = child;
          break;
        }
      }

      if (!next)
        return false;

      cur = next;
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
