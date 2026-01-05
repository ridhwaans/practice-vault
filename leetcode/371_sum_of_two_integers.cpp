#include <bitset>
#include <iostream>
#include <string>
#include <utility>

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }

    int getSumUnsigned8Bit(int a, int b) {
        std::bitset<8> binary_a(a);
        std::bitset<8> binary_b(b);
        std::bitset<8> binary_sum;
        bool carry = false;
        // std::bitset indexing default order is lsb to msb
        for (int i = 0; i < binary_a.size(); i++) {
            bool sum = (binary_a[i] ^ binary_b[i]) ^ carry; 
            carry = (binary_a[i] & binary_b[i]) | (binary_a[i] & carry) | (binary_b[i] & carry);
            binary_sum[i] = sum; 
        }
        std::cout << "bitset sum is " << binary_sum << "\n";
        std::string binary_str_sum = binary_sum.to_string();

        std::cout << "binary string sum is " << binary_str_sum << "\n";
        int int_sum = std::stoi(binary_str_sum, nullptr, 2);
        std::cout << "int sum is " << int_sum << "\n";
        return int_sum;
    }
};

int main(int argc, char *argv[]){
    Solution solution;
    std::vector<std::pair<int,int>> inputs = {
            {1,2},
            {2,3},
            {-12,-8}
    };

    auto run = [&](int a, int b){
            return solution.getSum(a,b);
    };
    
    for (const auto& [a, b] : inputs) {
        std::cout << "getSum( " << a << ", " << b << " ) = "
              << "\n" << run(a, b) << "\n";
    }
    return 0;
}
