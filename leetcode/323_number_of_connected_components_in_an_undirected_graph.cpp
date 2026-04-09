#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
  void dfs(unordered_map<int, int> &visited,
           unordered_map<int, unordered_set<int>> &adj, int n) {
    if (visited[n])
      return;
    visited[n] = 1; // currently visiting
    for (const int &neighbour : adj[n]) {
      dfs(visited, adj, neighbour);
    }
  }
  int countComponents(int n, vector<vector<int>> &edges) {
    unordered_map<int, unordered_set<int>> adj;
    for (vector<int> &e : edges) {
      // double sides for undirected
      adj[e[0]].insert(e[1]);
      adj[e[1]].insert(e[0]);
    }
    unordered_map<int, int> visited;
    // elements inside set are immutable so have to use const
    for (const auto &[key, value] : adj) {
      visited[key] = 0;
    }

    int connectedComponents = 0;
    // dont loop over adj because it doesnt necessarily contain all nodes.
    // isolated nodes dont get inserted
    for (int i = 0; i < n; i++) {
      if (visited[i] == 0) {
        connectedComponents++;
        // if (!dfs(visited, adj, 0, -1)) return false;
        dfs(visited, adj, i);
      }
    }
    return connectedComponents;
  }
};
