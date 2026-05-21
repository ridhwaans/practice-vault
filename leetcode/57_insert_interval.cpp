#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> results;
    bool inserted = false;

    for (const auto &interval : intervals) {
      if (newInterval.back() < interval.front()) {
        if (!inserted) {
          results.push_back(newInterval);
          inserted = true;
        }
        results.push_back(interval);
      } else if (newInterval.front() > interval.back()) {
        results.push_back(interval);
      } else {
        newInterval = {min(newInterval.front(), interval.front()),
                       max(newInterval.back(), interval.back())};
      }
    }
    if (!inserted)
      results.push_back(newInterval);
    return results;
  }
};
