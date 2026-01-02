#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++){
                if (i > 0 && nums[i] == nums[i - 1]) { continue; }
                int l = i + 1;
                int r = nums.size() - 1;

                while (l < r){
                    if (nums[i] + nums[l] + nums[r] == 0){
                        results.push_back({nums[i], nums[l], nums[r]});
                        while ((l < r) && nums[l] == nums[l + 1]) { l++; }
                        while ((l < r) && nums[r] == nums[r - 1]) { r--; }
                        l++;
                        r--;
                    } else if (nums[i] + nums[l] + nums[r] > 0) {
                         r--;
                    } else if (nums[i] + nums[l] + nums[r] < 0) {
                        l++;
                    }                        
                }
        }
        return results;
    }
};


int main(int argc, char *argv[]) {
    std::cout << "You have entered " << argc << " arguments." << std::endl;

    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument [" << i << "]: " << argv[i] << std::endl;
    }

    Solution solution;
    vector<int> arr {-1,0,1,2,-1,-4};
    vector<vector<int>> answer =  solution.threeSum(arr);
    
    for (auto &triple : answer){
            cout <<  "[";
            for (int i = 0; i < triple.size(); i++){
                    cout << triple[i];
                    if (i < triple.size()) cout << ", ";
            }
            cout << "]\n";
    }
}
