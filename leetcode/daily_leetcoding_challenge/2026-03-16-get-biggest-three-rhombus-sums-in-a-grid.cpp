#include <set>
using namespace std;

class Solution {
public:
  set<int> results;
  vector<vector<int>> d1, d2;

  void buildDiagonals(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();

    d1.assign(m + 1, vector<int>(n + 1, 0));
    d2.assign(m + 1, vector<int>(n + 2, 0));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        d1[i + 1][j + 1] = g[i][j] + d1[i][j];

    for (int i = 0; i < m; i++)
      for (int j = n - 1; j >= 0; j--)
        d2[i + 1][j] = g[i][j] + d2[i][j + 1];
  }

  int getSum(int &i, int &j, int &L, vector<vector<int>> &grid) {
    if (L == 0)
      return grid[i][j]; // single cell case

    int sum = 0;

    // top -> right
    for (int k = 0; k < L; k++) {
      sum += grid[i - L + k][j + k];
    }

    // right -> bottom
    for (int k = 0; k < L; k++) {
      sum += grid[i + k][j + L - k];
    }

    // bottom -> left
    for (int k = 0; k < L; k++) {
      sum += grid[i + L - k][j - k];
    }

    // left -> top
    for (int k = 0; k < L; k++) {
      sum += grid[i - k][j - L + k];
    }

    return sum;
  }

  int efficientGetSum(int i, int j, int L, vector<vector<int>> &g) {
    if (!L)
      return g[i][j];

    int r1 = i - L, c1 = j;
    int r2 = i, c2 = j + L;
    int r3 = i + L, c3 = j;
    int r4 = i, c4 = j - L;

    int s = 0;

    s += d1[r2 + 1][c2 + 1] - d1[r1][c1];
    s += d2[r3 + 1][c3] - d2[r2][c2 + 1];
    s += d1[r3 + 1][c3 + 1] - d1[r4][c4];
    s += d2[r4 + 1][c4] - d2[r1][c1 + 1];

    return s - g[r1][c1] - g[r2][c2] - g[r3][c3] - g[r4][c4];
  }

  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    buildDiagonals(grid);

    for (int i = 0; i < rowSize; i++) {
      for (int j = 0; j < colSize; j++) {
        int L = 0;
        while (i - L >= 0 && i + L < rowSize && j - L >= 0 && j + L < colSize) {
          results.insert(efficientGetSum(i, j, L, grid));
          L += 1;
        }
      }
    }

    vector<int> finalResult;
    auto it = results.rbegin();
    for (int i = 0; i < 3 && it != results.rend(); i++, it++) {
      finalResult.push_back(*it);
    }
    return finalResult;
  }
};
