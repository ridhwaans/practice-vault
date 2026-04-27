#include <vector>

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> spiralArr;
    int R = matrix.size();
    int C = matrix[0].size();
    int OR = 0, OC = 0;
    // wrong
    // while (R < -1 && C -1){
    while (OR < R && OC < C) {
      // right
      for (int i = OC; i < C; i++) {
        spiralArr.push_back(matrix[OR][i]);
      }
      // down
      for (int i = OR + 1; i < R - 1; i++) {
        spiralArr.push_back(matrix[i][C - 1]);
      }
      // left
      if (OR < R - 1) { // edge case guard
        for (int i = C - 1; i >= OC; i--) {
          spiralArr.push_back(matrix[R - 1][i]);
        }
      }
      // up
      if (OC < C - 1) { // edge case guard
        for (int i = R - 2; i >= OR + 1; i--) {
          spiralArr.push_back(matrix[i][OC]);
        }
      }
      R--;
      C--;
      OR++;
      OC++;
    }
    return spiralArr;
  }
};
