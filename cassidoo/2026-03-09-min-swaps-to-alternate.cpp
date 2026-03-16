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

    if (abs(a_count - b_count) > 1)
      return -1;

    // helper lambda to count mismatches for a given starting char
    auto countSwaps = [&](char first) {
      int mismatches = 0;
      for (int i = 0; i < n; i++) {
        // alternating a and b one liner
        char expected = (i % 2 == 0) ? first : (first == 'a' ? 'b' : 'a');
        if (s[i] != expected)
          mismatches++;
      }
      return mismatches / 2;
    };

    if (a_count > b_count)
      return countSwaps('a');
    if (b_count > a_count)
      // start with b alternating
      return countSwaps('b');
    return min(countSwaps('a'), countSwaps('b'));
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
