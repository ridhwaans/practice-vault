#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool dfs(int course, unordered_map<int, int> &visited,
           unordered_map<int, vector<int>> &adj) {
    // check visit status
    if (visited[course] == 0)
      return false;
    if (visited[course] == 1)
      return true;
    if (visited[course] == -1)
      visited[course] = 0; // visiting

    // check courses that depend on this course
    for (const int prereq : adj[course]) {
      /*
      mistakes - do not reset because visited in not in this call only, it
      stores the global state of each course missing return if dfs call is false
      time limit exceeded because i loop prerequisites each time to find the
      current course another approach is to restructure prerequisites where each
      unique course maps to a list of prereqs for faster lookup (aka. adjacency
      list) then pass that rather than prerequisites have return true at bottom
      but missed if visited is 1 return true at beginning
      */
      // dfs(pair[1], visited, prerequisites);
      // visited[pair[1]] = -1; // reset
      if (!dfs(prereq, visited, adj))
        return false;
    }

    visited[course] = 1; // finished visiting
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, int>
        visited; // not using set because checking for cycles in tristate

    // rookie mistake - adjacency list direction is p[1] push_back p[0] not the
    // other way
    unordered_map<int, vector<int>> adj;
    for (auto &p : prerequisites) {
      adj[p[1]].push_back(p[0]);
    }

    for (int i = 0; i < numCourses; i++) {
      visited[i] = -1; // never visited
    }
    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i, visited, adj))
        return false;
    }
    return true;
  }
};
