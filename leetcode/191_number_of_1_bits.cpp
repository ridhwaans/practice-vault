#include <bitset>

class Solution {
public:
  int hammingWeight(int n) {
    std::bitset<32> binary_n(n);
    int set_bits = 0;

    for (int i = 0; i < binary_n.size(); i++) {
      if (binary_n[i] == 1)
        set_bits++;
    }
    return set_bits;
  }
};
