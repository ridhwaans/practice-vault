#include <unordered_map>
#include <utility> // pair

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    int l = 0, r = 0;

    // // edge case - storing indices instead because substr() memory allocation
    // causes memory limit exceeded
    // string minSubstr = "";
    pair<int, int> minSubstr = {-1, -1};
    unordered_map<char, int> store;
    // // bug - need to store occurrences in string t in store, not 0
    // for (auto &c : t){
    //     store[c] = 0;
    // }
    for (auto &c : t) {
      store[c] += 1;
    }
    int need = store.size(), have = 0;
    unordered_map<char, int> window;
    for (r; r < s.size(); r++) {
      window[s[r]] += 1;
      // if letter is target and window contains target occurrences of letter
      // (not necessarily 1 per letter)
      if (store.find(s[r]) != store.end() && window[s[r]] == store[s[r]]) {
        have += 1;
      }

      // perform logic only when match found to
      while (have == need) {
        // bug - substr(l,r) is now start & end indices, it is start at l, take
        // r characters bug - checking empty pair is wrong
        // if (minSubstr.second - minSubstr.first + 1 == 0) minSubstr =
        // make_pair(l, r);
        // {} cannot be plainly on right side of ternary because it has no type
        // without cast
        if (minSubstr.first == -1)
          minSubstr = {l, r};
        minSubstr = ((r - l + 1) > (minSubstr.second - minSubstr.first + 1))
                        ? minSubstr
                        : make_pair(l, r);

        // note - watch the timing of incrementing l and recording
        // windows[s[l]]. compare, record then shrink from the left
        window[s[l]] -= 1;
        // if target letter is leaving window and falls below target occurrence
        if (store.find(s[l]) != store.end() && window[s[l]] < store[s[l]]) {
          have -= 1;
        }
        l += 1;
      }
    }
    if (minSubstr.first == -1)
      return "";
    return s.substr(minSubstr.first, minSubstr.second - minSubstr.first + 1);
  }
};
