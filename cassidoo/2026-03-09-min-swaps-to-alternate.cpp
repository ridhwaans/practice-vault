#include <cmath> // for abs
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int minSwapsToAlternate(const string &s) {
    int n = s.size();
    int a_count = 0, b_count = 0;
    unordered_set<char> allowed = {'a', 'b'};
    for (char c : s) {
      if (allowed.find(c) == allowed.end()) {
        cout << "Only a and b allowed" << endl;
        return -1;
      }
      if (c == 'a')
        a_count++;
      if (c == 'b')
        b_count++;
    }
    int swaps = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i % 2 == 0 && s[i] != 'a' && a_count > 0) {
        swaps++;
        a_count--;
        // b_count--;
      } else if (i % 2 != 0 && s[i] != 'b' && b_count > 0) {
        swaps++;
        // a_count--;
        b_count--;
      } else {
        if (s[i] == 'a')
          a_count--;
        if (s[i] == 'b')
          b_count--;
      }
    }
    return swaps / 2;
  }
};

int main() {
  string inputs[3] = {"aabb", "aaab", "aaaabbbb"};

  Solution solution;
  for (string s : inputs) {
    printf("minSwapsToAlternate '%s': %d\n", s.c_str(),
           solution.minSwapsToAlternate(s));
  }
}
