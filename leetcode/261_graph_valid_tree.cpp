#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool dfs(unordered_map<int, int> &visited, int n, int parent,
           unordered_map<int, unordered_set<int>> &adj) {
    if (visited[n] == 2) {
      return true;
    }
    if (visited[n] == 1) {
      return false; // cycle
    }
    visited[n] = 1; // currently visiting
    unordered_set<int> neighbours = adj[n];
    // logic bug: dont return after first neighbour, explore all neighbours
    // for (auto neighbour : neighbours){
    //     return dfs(visited, neighbour, adj);
    // }
    for (auto neighbour : neighbours) {
      if (neighbour == parent)
        continue;
      if (!dfs(visited, neighbour, n, adj)) {
        return false;
      }
    }
    visited[n] = 2; // finished visiting
    return true;
  }

  bool validTree(int n, vector<vector<int>> &edges) {
    // edge case
    if (edges.size() != n - 1)
      return false;

    unordered_map<int, unordered_set<int>> adj;
    unordered_map<int, int> visited;
    for (auto &pair : edges) {
      // insert both ways because undirected edge
      adj[pair[0]].insert(pair[1]);
      adj[pair[1]].insert(pair[0]);
    }
    if (!dfs(visited, 0, -1, adj))
      return false;

    for (pair<const int, unordered_set<int>> &p : adj) {
      cout << p.first << ": ";
      unordered_set<int> &items = p.second;
      for (auto item : items) {
        cout << item << ", ";
      }
      cout << endl;
    }

    for (pair<const int, unordered_set<int>> item : adj) {
      return dfs(visited, item.first, -1, adj);
    }
    return true;
  }
};
