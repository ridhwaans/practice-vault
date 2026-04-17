/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include <algorithm>
#include <vector>

class Solution {
public:
  int minMeetingRooms(vector<Interval> &intervals) {
    vector<int> starts;
    vector<int> ends;
    for (const auto &i : intervals) {
      starts.push_back(i.start);
      ends.push_back(i.end);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int rooms = 0, ans = 0;
    int startptr = 0, endptr = 0;

    while (startptr < starts.size()) {
      if (starts[startptr] < ends[endptr]) {
        rooms++;
        startptr++;
      } else {
        rooms--;
        endptr++;
      }
      ans = max(ans, rooms);
    }
    return ans;
  }
};
