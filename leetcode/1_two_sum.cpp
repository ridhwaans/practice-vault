#include <vector>
#include <map>
#include <cstddef>

class Solution {
public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::map<int,int> differences;
            for (std::size_t i = 0; i < nums.size(); i++){
                if (differences.count(target-nums[i])==0){
                        differences.insert( std::pair<int,int>(nums[i], static_cast<int>(i)));
                } else {
                        return {static_cast<int>(i), differences[target - nums[i]]}; 
                }
          }
            return {};
        }
};
