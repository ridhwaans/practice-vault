#include <iostream>
#include <bitset>

class Solution {
public:
    int reverse32BitSet(int n){
            std::bitset<32> input_n(n);
            std::bitset<32> reversed_n;
            for (int i = 0;i < 32; i++){
                reversed_n[i] = input_n[31 - i];
            }
            return static_cast<int>(reversed_n.to_ulong());
    }
    int reverseBits(int n){
        int res = 0;
        for (int i = 0; i < 32; i++){
            res = res | (((n >> i) & 1) << (31 - i));
        }       
        return res;
    }
};

            
            
int main(int argc, char **argv){
    Solution solution;
    std::cout << "2147483644 reversed via bitset: " << solution.reverse32BitSet(2147483644) << std::endl;
    std::cout << "43261596 reversed via bitset: " << solution.reverse32BitSet(43261596) << std::endl;
    
    std::cout << "2147483644 reversed: " << solution.reverseBits(2147483644) << std::endl;
    std::cout << "43261596 reversed: " << solution.reverseBits(43261596) << std::endl;
}
