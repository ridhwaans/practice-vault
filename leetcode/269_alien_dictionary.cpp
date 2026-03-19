#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  // DFS
  bool dfs(auto c, auto &visited, auto &adj, string &answer) {
    if (visited[c] == 2) {
      return true;
    };
    if (visited[c] == 1)
      return false; // cycle
    visited[c] = 1; // visiting
    for (auto &neighbour : adj[c]) {
      if (!dfs(neighbour, visited, adj, answer)) {
        return false;
      }
    }
    visited[c] = 2; // finished visiting
    answer += c;
    return true;
  }

  string foreignDictionary(vector<string> &words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> visited; // path
    string answer;

    for (const string &w : words) {
      for (char c : w) {
        adj[c];
      }
    }
    // build graph edges
    for (int i = 0; i < words.size() - 1; i++) {
      string &w1 = words[i];
      string &w2 = words[i + 1];
      // invalid prefix case
      int minLen = min(w1.size(), w2.size());
      if (w1.substr(0, minLen) == w2.substr(0, minLen) &&
          w1.size() > w2.size()) {
        return "";
      }

      for (int j = 0; j < minLen; j++) {
        if (w1[j] != w2[j]) { // neighbor found
          adj[w1[j]].insert(w2[j]);
          break;
        }
      }
    }
    // loop all keys in map, values are negligible
    for (auto &[c, _] : adj) {
      if (!dfs(c, visited, adj, answer)) {
        return "";
      }
    }

    // postorder traversal
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
