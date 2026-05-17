#include <cstdlib>
#include <unordered_set>
#include <vector>

using namespace std;

struct TrieNode {
  int val;
  bool isWord;
  vector<TrieNode *> children;
  // mistake - missed type on constructor TrieNode(x):
  TrieNode(int x) : val(x), isWord(false) {}
};

class Solution {
private:
  const char dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  TrieNode *root = new TrieNode('\0');
  unordered_set<string> foundWords;
  int R, C;

public:
  void insertWord(string word) {
    TrieNode *cur = root;

    for (char c : word) {
      bool found = false;

      // mistake - used by reference on wrong side (right-hand &cur)
      vector<TrieNode *> &children = cur->children;
      for (auto child : children) {
        if (child->val == c) {
          found = true;
          cur = child;
        }
      }

      if (!found) {
        children.push_back(new TrieNode(c));
        cur = children.back();
      }
    }
    cur->isWord = true;
  }

  // mistake - initially bool. changed to return TreeNode* to combine checking
  // startsWith and fetching node to check isWord
  TrieNode *startsWith(string word) {
    TrieNode *cur = root;

    for (char c : word) {
      bool found = false;
      // mistake - removed & which makes a vector a pointer
      vector<TrieNode *> children = cur->children;

      for (auto child : children) {
        if (child->val == c) {
          cur = child;
          found = true;
        }
      }
      if (!found)
        return nullptr;
    }
    return cur;
  }

  bool dfs(int x, int y, vector<vector<char>> &board,
           vector<vector<int>> &visited, string word, TrieNode *node) {
    if (x < 0 || y < 0 || x > R - 1 || y > C - 1)
      return false;
    if (visited[x][y] == 0)
      return false; // cannot revisit already in current path

    // mistake - dont do this anymore since node is a dfs param
    // word += board[x][y];
    // node = startsWith(word);

    // need to advance node
    TrieNode *child = nullptr;
    char c = board[x][y];
    for (auto next : node->children) {
      if (next->val == c) {
        child = next;
        break;
      }
    }
    if (!child)
      return false; // didnt find letter in predefined trie
    word += c;
    if (child->isWord && !foundWords.count(word))
      foundWords.insert(word);

    if (visited[x][y] == -1)
      visited[x][y] = 0; // currently visiting

    // dont return immediately because one path may contain a shorter word but
    // still continue into a longer word

    // mistake - initially used the trie backwards. insert all words into trie
    // before DFS
    // // mistake - find works with vector too, but not as a method
    // (words.find()) like set/map if (find(words.begin(), words.end(), word) !=
    // words.end()){
    //     insertWord(word);
    // }
    for (auto d : dir) {
      dfs(x + d[0], y + d[1], board, visited, word, child);
    }
    // mistake - did not untrack after leaving cell. for Word Search, the rule
    // is a cell cannot repeat in the same path, not the whole DFS call (cut 3
    // states to 2) visited[x][y] = 1; // finished visiting
    visited[x][y] = -1; // unchoose/backtrack

    return true;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    R = board.size();
    C = board[0].size();
    // mistake - dont use malloc on vector
    // vector<vector<int>> visited = malloc(R, (vector<int>, C));
    vector<vector<int>> visited(R, vector<int>(C, -1));

    for (auto word : words) {
      insertWord(word);
    }

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        // mistake - no longer need reset loop since i backtrack/reset cells at
        // end of dfs. so do not need words as dfs param
        // // reset for next
        // for (int i = 0; i < R; i++){
        //     for (int j = 0; j < C; j++){
        //         visited[i][j] = -1;
        //     }
        // }
        // mistake - missed carrying node pointer as dfs param
        dfs(i, j, board, visited, "", root);
      }
    }
    // convert set to string
    return vector<string>(foundWords.begin(), foundWords.end());
  }
};
