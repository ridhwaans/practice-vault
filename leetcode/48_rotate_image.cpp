#include <vector>

using namespace std;
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int R = matrix.size();
    int C = matrix[0].size();
    int OR = 0, OC = 0;
    while (OR < R) {
      // i = OR; < R; i++ didnt work
      // i should be offset, not absolute index
      for (int i = 0; i < R - OR - 1; i++) {
        // go clockwise
        int temp = matrix[OR][OC + i];
        matrix[OR][OC + i] = matrix[R - 1 - i][OC];
        matrix[R - 1 - i][OC] = matrix[R - 1][C - 1 - i];
        matrix[R - 1][C - 1 - i] = matrix[OR + i][C - 1];
        matrix[OR + i][C - 1] = temp;
      }
      R--;
      C--;
      OR++;
      OC++;
    }
  }
};
