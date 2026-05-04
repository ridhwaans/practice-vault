#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> store;
    if (s.size() != t.size())
      return false;
    for (char &c : s) {
      store[c] += 1;
    }
    for (char &c : t) {
      if (store.find(c) == store.end())
        return false;
      if (store[c] == 0) {
        return false;
      } else {
        store[c] -= 1;
      }
    }
    return true;
  }
};
