#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> resMap;
    vector<vector<string>> res;

    for (auto &str : strs) {
      // create key
      // alternative is to use a sorted string as the key
      string key = "";
      map<char, int> freq;
      for (char c : str) {
        freq[c] += 1;
      }
      for (auto &[k, v] : freq) {
        key += k + to_string(v);
      }
      resMap[key].push_back(str);
    }

    for (auto &[k, v] : resMap) {
      vector<string> subList;
      for (string sameStrs : v) {
        subList.push_back(sameStrs);
      }
      res.push_back(subList);
    }
    return res;
  }
};
