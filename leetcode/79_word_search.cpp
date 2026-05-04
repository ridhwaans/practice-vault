#include <vector>

using namespace std;
class Solution {
public:
  // some cases failed because bug with directions (no diagonal) even though dfs
  // logic was valid vector<pair<int,int>> directions = {{0,0}, {0,1}, {1,0},
  // {1,1}};
  vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  int R, C;
  vector<vector<int>> visited;

  bool dfs(vector<vector<char>> &board, string word, pair<int, int> pos,
           int i) {
    if (pos.first < 0 || pos.first >= R || pos.second < 0 || pos.second >= C) {
      return false;
    }

    if (visited[pos.first][pos.second] == 1) {
      return false;
    }
    if (word[i] != board[pos.first][pos.second]) {
      return false;
    }

    // word[i] == board[pos.first][pos.second] &&
    if (i == word.size() - 1) {
      return true;
    }

    visited[pos.first][pos.second] = 1;

    for (auto &d : directions) {
      if (dfs(board, word,
              make_pair(pos.first + d.first, pos.second + d.second), i + 1))
        return true;
    }
    // dfs session failed. reset for next dfs session
    visited[pos.first][pos.second] = 0;
    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    R = board.size();
    C = board[0].size();
    visited.assign(R, vector<int>(C, 0));

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (dfs(board, word, make_pair(r, c), 0))
          return true;
      }
    }
    return false;
  }
};
