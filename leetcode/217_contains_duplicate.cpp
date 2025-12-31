class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> bookkeeping;
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
