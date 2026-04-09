#include <queue>
using namespace std;
class Solution {

public:
  int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    // remember all 1s that were visited and floodfill with bfs
    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    int num = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '1' && visited[i][j] == 0) {
          bfs(grid, {i, j}, visited);
          num++;
        }
      }
    }
    return num;
  }

  int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  void bfs(vector<vector<char>> &grid, pair<int, int> pos,
           vector<vector<int>> &visited) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.first][pos.second] = 1;

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int *d : directions) {
        int nx = x + d[0], ny = y + d[1];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
            visited[nx][ny] == 0 && grid[nx][ny] == '1') {
          visited[nx][ny] = 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
};
