#include <climits>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int longest = 0;
    int l = 0, r = 0;
    // start both at 0
    for (r = l; r < s.size(); r++) {
      while (set.find(s[r]) != set.end()) {
        // need to remove left side, removing right side is a bug
        set.erase(s[l]);
        l++;
      }
      set.insert(s[r]);
      longest = max(longest, r - l + 1);
    }
    return longest;
  }
};
