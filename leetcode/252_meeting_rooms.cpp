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

class Solution {
public:
  bool canAttendMeetings(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
      if (a.start == a.start)
        return a.end < b.end;
      return a.start < b.start;
    });

    bool canAttend = true;
    int cur = 0;
    while (canAttend) {
      if (cur == intervals.size())
        break;
      if (cur == 0) {
        cur++;
        continue;
      }
      if (intervals[cur - 1].end > intervals[cur].start)
        canAttend = false;
      cur++;
    }
    return canAttend;
  }
};
