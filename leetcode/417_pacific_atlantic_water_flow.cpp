#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int directions[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  void flow(vector<vector<int>> &g, int R, int C, pair<int, int> cell,
            set<pair<int, int>> &collection) {
    // moved insert({x,y}) to beginning because boundary cells dont get recorded
    // unless reached from another
    collection.insert(cell);
    for (auto d : directions) {
      int x = cell.first + d[0], y = cell.second + d[1];
      if (x >= 0 && x < R && y >= 0 && y < C &&
          g[x][y] >= g[cell.first][cell.second] &&
          collection.find({x, y}) == collection.end()) {
        flow(g, R, C, {x, y}, collection);
      } else {
        continue;
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    vector<pair<int, int>> pacific;
    vector<pair<int, int>> atlantic;
    set<pair<int, int>> pvisited;
    set<pair<int, int>> avisited;
    int R = heights.size();
    int C = heights[0].size();
    for (int i = 0; i < R; i++) {
      pacific.push_back(make_pair(i, 0));
      atlantic.push_back(make_pair(i, C - 1));
    }
    for (int j = 0; j < C; j++) {
      pacific.push_back(make_pair(0, j));
      atlantic.push_back(make_pair(R - 1, j));
    }

    for (auto cell : pacific) {
      flow(heights, R, C, cell, pvisited);
    };
    for (auto cell : atlantic) {
      flow(heights, R, C, cell, avisited);
    };

    vector<vector<int>> result;

    for (auto &p : pvisited) {
      if (avisited.count(p)) {
        result.push_back({p.first, p.second});
      }
    }
    return result;
  }
};
