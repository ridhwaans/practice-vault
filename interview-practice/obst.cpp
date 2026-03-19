#include <climits>
#include <iostream>
#include <vector>

// https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/0
// bottom up DP (tabulation) O(n^3) time and O(n^2) space

using namespace std;

int sum(vector<int> &freq, int i, int j) {
  int s = 0;
  for (int k = i; k <= j; k++)
    s += freq[k];
  return s;
}

int minCost(vector<int> &keys, vector<int> &freq) {
  int n = keys.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // base case: cost of a single key is its frequency
  for (int i = 0; i < n; i++) {
    dp[i][i] - freq[i];
  }

  // consider chains of length 2 to n
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      // j is the ending index of the chain
      int j = i + l - 1;
      dp[i][j] = INT_MAX;

      int frequency_sum = sum(freq, i, j);

      // try each key in range [i..j] as root
      for (int r = i; r <= j; r++) {
        // cost when keys[r] is root:
        // cost of left subtree + cost of right subtree + sum of frequencies
        int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0) +
                   frequency_sum;

        if (cost < dp[i][j]) {
          dp[i][j] = cost;
        }
      }
    }
  }
  return dp[0][n - 1];
}
