#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>>
  minDistanceToNearestFireStation(vector<vector<int>> grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    vector<pair<int, int>> fireStations;
    for (int m = 0; m < rowSize; m++) {
      for (int n = 0; n < colSize; n++) {
        if (grid[m][n] == 1)
          fireStations.push_back({m, n});
      }
    }

    vector<vector<int>> result(rowSize, vector<int>(colSize, 0));
    for (int m = 0; m < rowSize; m++) {
      for (int n = 0; n < colSize; n++) {
        vector<int> pos = {m, n};
        if (grid[m][n] == 1) {
          result[m][n] = 0; // fire station
        } else {
          result[m][n] =
              minDistance({m, n}, fireStations, rowSize, colSize, grid);
        }
      }
    }
    return result;
  }

  int minDistance(vector<int> pos, vector<pair<int, int>> stations, int R,
                  int C, vector<vector<int>> &grid) {
    queue<tuple<int, int, int>> q;

    vector<vector<bool>> visited(R, vector<bool>(C, false));

    vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // start at 0 steps
    q.push({pos[0], pos[1], 0});
    visited[pos[0]][pos[1]] = true;

    while (!q.empty()) {
      auto next = q.front();
      q.pop();
      for (auto d : directions) {
        auto nx = get<0>(next) + d[0];
        auto ny = get<1>(next) + d[1];
        auto steps = get<2>(next);
        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
          continue;
        if (visited[nx][ny] == true)
          continue;
        // auto p = make_pair(nx, ny);
        // if (find(stations.begin(), stations.end(), p) != stations.end()) {
        //   return steps + 1;
        // }
        if (grid[nx][ny] == 1)
          return steps + 1;
        visited[nx][ny] = true;
        q.push({nx, ny, steps + 1});
      }
    }
    return -1;
  }
};

vector<vector<int>> build(int *arr, int rows, int cols) {
  vector<vector<int>> v(rows, vector<int>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      v[i][j] = arr[i * cols + j];
    }
  }
  return v;
}

void printGrid(const vector<vector<int>> &g) {
  for (const auto &row : g) {
    for (int x : row) {
      printf("%d ", x);
    }
    printf("\n");
  }
}

void runTest(int *inputArr, int *expectedArr, int rows, int cols) {
  Solution sol;

  vector<vector<int>> input = build(inputArr, rows, cols);
  vector<vector<int>> expected = build(expectedArr, rows, cols);

  printf("Input:\n");
  printGrid(input);
  vector<vector<int>> result = sol.minDistanceToNearestFireStation(input);

  printf("Expected:\n");
  printGrid(expected);

  printf("Got:\n");
  printGrid(result);
}

int main(int argc, char **argv) {
  // Test 1
  int input1[] = {2, 0, 1, 0, 2, 0, 1, 0, 2};

  int expected1[] = {2, 1, 0, 1, 2, 1, 0, 1, 2};

  runTest(input1, expected1, 3, 3);

  // Test 2
  int input2[] = {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1};

  int expected2[] = {0, 1, 2, 0, 1, 2, 2, 1, 1, 2, 2, 1, 0, 1, 2, 0};

  runTest(input2, expected2, 4, 4);

  return 0;
}
