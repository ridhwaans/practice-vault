#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int,int> bookkeeping;
        for (auto i: nums) {
            bookkeeping[i] = bookkeeping[i] + 1;
        }
        for (auto const& [key, val] : bookkeeping){
            if (val > 1){
                return true;
            }
        }
        return false;
    }
};
