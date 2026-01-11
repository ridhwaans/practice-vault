#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cassert>

int maxScoreWithOneReset(const std::vector<int> &nums){
    int curSum = 0, maxSum = INT_MIN;
    bool reset;
    for (int i = 0; i < nums.size(); i++){
        curSum += nums[i];
        if (curSum < 0 && !reset){
                curSum = 0;
                reset = true;
        }
        maxSum = std::max(curSum, maxSum);
    }
    return maxSum;
}

int main(int argc, char *argv[]){
   std::vector<std::vector<int>> testCases = {
        {2, -1, 2, -5, 2, 2},
        {4, -10, 3, 2, -1, 6},
        {-50, -2, -3}
    };
    int expected[] = {4, 10, 0};

    for (int i = 0; i < testCases.size(); i++) {
        int res = maxScoreWithOneReset(testCases[i]);
        assert(res == expected[i]);
        std::cout << res << "\n";
    }
    std::cout << "All tests passed" << std::endl;
}
