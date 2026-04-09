#include <climits>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> nums_set;
    for (auto &n : nums) {
      nums_set.insert(n);
    }
    int longest = 0;
    /*
    time limit exceeded
    for (int &n : nums){
    */
    for (int n : nums_set) {
      if (nums_set.find(n - 1) == nums_set.end()) {
        // beginning of seq
        bool nextConsecutive = true;
        int seqLen = 0;
        while (nextConsecutive) {
          seqLen++;
          nextConsecutive = nums_set.find(n + seqLen) != nums_set.end();
        }
        longest = max(longest, seqLen);
      }
    }
    return longest;
  }
};
