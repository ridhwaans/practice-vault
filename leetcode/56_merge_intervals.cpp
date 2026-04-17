#include <algorithm>
#include <cstdio>
#include <iterator>
#include <vector>

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> results;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    for (auto it = intervals.begin(); it != intervals.end();) {
      auto it2 = it + 1;
      if (it2 == intervals.end()) {
        results.push_back(*it);
        break;
      }

      int vecBack = (*it)[1];
      int vec2Front = (*it2)[0];
      while (it2 != intervals.end() && vec2Front <= vecBack) {
        vecBack = max(vecBack, (*it2)[1]);
        it2++;
        if (it2 != intervals.end()) {
          vec2Front = (*it2)[0];
        }
      }

      results.push_back({min((*it)[0], vec2Front), vecBack});
      it = it2;
    }
    return results;
  }
};
