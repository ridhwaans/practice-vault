#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest_positive = nums.at(0);
        int largest_negative = nums.at(0);
        int largest_product = nums.at(0);
        bool first = true;

        for (const int& num: nums){
            if (first) {
                first = false; 
                continue;
            }
            if (num < 0){
                swap(largest_positive, largest_negative);                
            }
            if (num * largest_positive > num){
                largest_positive = num * largest_positive;
            } else {
                largest_positive = num;
            }
            if (num * largest_negative < num){
                largest_negative = num * largest_negative;
            } else {
                largest_negative = num;
            }
            largest_product = max(largest_product, largest_positive);
        }
        return largest_product;
    }    
};
