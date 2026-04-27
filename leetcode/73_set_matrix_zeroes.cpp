#include <vector>

class Solution {
public:
  int R, C;

  void setZeroes(vector<vector<int>> &matrix) {
    int R = matrix.size();
    int C = matrix[0].size();

    bool rowZero = false;

    // flag zeroes
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (matrix[r][c] == 0) {
          r == 0 ? rowZero = true : matrix[r][0] = 0;
          matrix[0][c] = 0;
        }
      }
    }

    // set zeroes to rows and cols
    for (int r = 1; r < R; r++) {
      for (int c = 1; c < C; c++) {
        if (matrix[r][0] == 0 || matrix[0][c] == 0) {
          matrix[r][c] = 0;
        }
      }
    }

    // zero first column
    if (matrix[0][0] == 0) {
      for (int r = 0; r < R; r++) {
        matrix[r][0] = 0;
      }
    }

    // zero first row
    if (rowZero) {
      for (int c = 0; c < C; c++) {
        matrix[0][c] = 0;
      }
    }
  }
};
