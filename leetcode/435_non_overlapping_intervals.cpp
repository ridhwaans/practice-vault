#include <vector>

using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int ans = 0;

    sort(intervals.begin(), intervals.end(),
         [](const vector<int> a, const vector<int> b) {
           if (a[0] != b[0])
             return a[0] < b[0];
           return a[1] < b[1];
         });

    int n = intervals.size();
    int curEnd = intervals[0][1];
    for (int i = 1; i < n; i++) {
      // overlap
      if (intervals[i][0] < curEnd) {
        curEnd = min(curEnd, intervals[i][1]);
        ans++;
      } else {
        curEnd = intervals[i][1];
      }
    }
    return ans;
  }
};
