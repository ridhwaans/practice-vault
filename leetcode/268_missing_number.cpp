#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> appeared(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++){
            appeared[nums[i]] = 1;
        }
        for (size_t i = 0; i <= appeared.size(); i++){
            if (appeared[i] == 0) return i;
        }
        return -1;
    }
};

int main(int argc, char *argv[]){
        Solution solution;
        vector<vector<int>> test_cases = {
            {3, 0, 1},
            {0, 1},
            {9, 6, 4, 2, 3, 5, 7, 0, 1}
        };
        int expected[] = {2,2,8};

        for (int i = 0; i < test_cases.size(); i++){
           int res = solution.missingNumber(test_cases[i]); 
           cout << "Actual: " << res << "\nExpected: " << expected[i] << "\n";
           assert(res == expected[i]);
        }
        cout << "all tests passed" << endl;
}
