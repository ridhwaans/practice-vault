#include <iostream>
#include <vector>
class Solution {
public:
    int bottomUp(int* n){
        int first = 1, second = 1;
        if (*n < 1) return 1;
        for (int i = 0; i < *n - 1;i++){
            int total = first + second;
            first = second;
            second = total;
        }
        return second;
    }
    int climbStairs(int n) {
       return bottomUp(&n); 
    }
};

int main(int argc, char **argv){
        Solution solution;
        std::vector<int> stairs {2, 3};
        std::vector<int> expected {2,3};
        for (int i = 0; i <stairs.size();i++){
                std::cout << "stairs n = " << stairs[i] << ": " << solution.climbStairs(stairs[i]) << ", Expected: " << expected[i] << "\n";
        }
}
