#include <iostream>
#include <algorithm>
#include <climits>
//#include <bits/stdc++.h>

class Solution {
public:
    int helper(int cur_max, int relative_idx, std::vector<int>& subarr) {
            int new_max = cur_max;
            for (int i = 0; i < subarr.size(); i++){
                int width = i; // + relative_idx;
                new_max = std::max(std::min(subarr[i], subarr.front()) * width, new_max);
        }
            return new_max;
    }
    int maxArea(std::vector<int>& height) {
        int area = INT_MIN;
        for (int i = 0; i < height.size(); i++){
                std::vector<int> subarr(height.begin() + i, height.end());
                area = helper(area, i, subarr);
        }
        return area;
    }
};

int main(int argc, char *argv[]){
        Solution solution;
        std::vector<int> arr = {1,8,6,2,5,4,8,3,7};
        std::cout << solution.maxArea(arr) << std::endl;
}
