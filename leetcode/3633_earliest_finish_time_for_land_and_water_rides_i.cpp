#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    int earliestFinish = INT_MAX;
    for (int i = 0; i < landStartTime.size(); i++) {
      for (int j = 0; j < waterStartTime.size(); j++) {
        // water first, then land
        int waterBegin =
            max(landStartTime[i], waterStartTime[j] + waterDuration[j]);
        earliestFinish = min(earliestFinish, waterBegin + landDuration[i]);

        // land first, then water
        int landBegin =
            max(waterStartTime[j], landStartTime[i] + landDuration[i]);
        earliestFinish = min(earliestFinish, landBegin + waterDuration[j]);
      }
    }
    return earliestFinish;
  }
};
