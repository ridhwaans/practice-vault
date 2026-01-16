#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
   int lengthOfLIS(vector<int>& nums) {
        vector<int> bottomUp(nums.size() + 1, 1);
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] < nums[j]){
                    bottomUp[j] = max(bottomUp[j], bottomUp[i] + 1);
                }
            }
        }
        return *max_element(bottomUp.begin(), bottomUp.end());
    }

    int lengthOfLISNLogN(vector<int>& nums) {
        int longest = 0;
        vector<int> arr {};
        for (int i = 0; i < nums.size(); i++){
            if (arr.empty() || nums[i] > arr.back()){
                arr.push_back(nums[i]);
                longest += 1;
            } else {
                // binary search & insert
                int l = 0, r = arr.size() - 1;
                while (l < r){
                    // didnt need cmath
                    int mid = static_cast<int>(round((r - l)/2));
                    if (arr[l] < nums[i] && nums[i] < arr[mid]){
                        r = mid;
                    } else if (arr[mid] < nums[i] && nums[i] < arr[r]){
                        l = mid;
                    }
                    l += 1;
                    r -= 1;
                }
                arr[l] = nums[i];
            }
        }
        // return longest or arr.size()
        return longest;
    }
};

int main(int argc, char **argv){
    Solution solution;
    vector<int> nums {10,9,2,5,3,7,101,18};
    cout << "nums=[10,9,2,5,3,7,101,18] length=" << solution.lengthOfLISNLogN(nums) << endl;
    nums  = {0,1,0,3,2,3};
    cout << "nums=[0,1,0,3,2,3] length=" << solution.lengthOfLISNLogN(nums) << endl;
    nums  = {7,7,7,7,7,7,7};
    cout << "nums=[0,1,0,3,2,3] length=" << solution.lengthOfLISNLogN(nums) << endl;
}
