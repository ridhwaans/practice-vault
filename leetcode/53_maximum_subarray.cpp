#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int cur_max = 0, global_max = INT_MIN;
    for (const int &i : nums) {
      cur_max = max(cur_max + i, i);
      global_max = max(global_max, cur_max);
    }
    return global_max;
  }
};
