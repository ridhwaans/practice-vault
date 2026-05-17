#include <vector>

using namespace std;

struct TrieNode {
  int val;
  bool isWord;
  vector<TrieNode *> children;
  // mistake - missed isWord in constructor and passing int x
  TrieNode(int x) : val(x), isWord(false) {}
};
class WordDictionary {
private:
  TrieNode *root;

public:
  WordDictionary() {
    // mistake - root is not a member pointer
    // TrieNode root = new TrieNode('\0');
    root = new TrieNode('\0');
  }

  void addWord(string word) {
    TrieNode *cur = this->root;
    for (char c : word) {
      bool found = false;
      vector<TrieNode *> &children = cur->children;
      for (auto child : children) {
        if (child->val == c) {
          cur = child;
          found = true;
          break;
        }
      }
      if (!found) {
        children.push_back(new TrieNode(c));
        cur = children.back();
      }
    }
    cur->isWord = true;
  }

  bool dfs(string substr, vector<TrieNode *> &children) {
    for (auto child : children) {
      if (substr[0] == '.' || substr[0] == child->val) {
        if (substr.size() == 1) {
          if (child->isWord)
            return true;
        } else {
          /*
          mistake - originally had wrong pattern if (!dfs(...)) return false;
          ... return true; if any child fails, whole search fails expresses AND
          but wildcard need OR
          */
          // explicit way to pass substring excluding first char to end
          if (dfs(substr.substr(1, substr.size() - 1), child->children)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool search(string word) {
    TrieNode *cur = this->root;
    for (int i = 0; i < word.size(); i++) {
      char c = word[i];
      if (c == '.') {
        // mistake - dont need to prefix &cur for dfs constructor, otherwise
        // error: non-const lvalue reference to type 'vector<TrieNode *>' cannot
        // bind to a temporary of type 'vector<TrieNode *> *' mistake - had to
        // change char c : word loop to indexed loop for substr(i) passes
        // substring excluding from beginning to current char and rest of the
        // word processed by dfs
        return dfs(word.substr(i), cur->children);
      }
      bool found = false;
      vector<TrieNode *> children = cur->children;
      for (auto child : cur->children) {
        if (child->val == c) {
          cur = child;
          found = true;
        }
      }
      if (!found) {
        return false;
      }
    }
    return cur->isWord;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
