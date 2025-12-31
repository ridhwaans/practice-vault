#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { 
        int n = nums.size();
        vector<int> results(n, 1); // initialize all 1s to not use push_back() which always appends
        int p = 1;
        for (int i = 0; i < n; i++) {
           results[i] = (p);
           p *= nums[i]; 
        }
        int s = 1;
        for (int i = n - 1; i >= 0; i--) {
            results[i] *= (s);
            s *= nums[i];
        }
        return results;
    }
};
