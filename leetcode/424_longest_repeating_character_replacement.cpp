#include <unordered_map>
class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> freq;
    int maxFreq = 0;
    int l = 0, r = 0;
    int longest = 0;
    for (auto &c : s) {
      freq[c] += 1;
      maxFreq = max(freq[c], maxFreq);
      while ((r - l + 1) - maxFreq > k) {
        // sliding window shift left
        freq[s[l]] -= 1;
        l++;
      }
      longest = max(longest, r - l + 1);
      r++;
    }
    return longest;
  }
};
