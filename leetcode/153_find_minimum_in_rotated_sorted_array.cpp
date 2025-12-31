class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        while (l < r){ // not using <= because it results in l index going past answer (l = l + 1, nums[l])
            int mid = l + (r - l) / 2;
            if (nums[r] > nums.at(mid)){
                r = mid;
            } else {
                l = mid;
                l = l + 1;
            }
        }
        return nums[l];
    }
};
