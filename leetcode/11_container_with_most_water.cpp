#include <iostream>
#include <algorithm>
#include <climits>

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
    int maxAreaBruteForce(std::vector<int>& iheight) {
        int area = INT_MIN;
        for (int i = 0; i < iheight.size(); i++){
                std::vector<int> subarr(iheight.begin() + i, iheight.end());
                area = helper(area, i, subarr);
        }
        return area;
    }

    int maxArea(std::vector<int>& height){
            int l = 0, r = height.size() - 1;
            int maxArea = INT_MIN;
            while (l < r){
                int area = (r - l) * std::min(height[l], height[r]);
                maxArea = std::max(area, maxArea);
                if (height[l] < height[r]){
                        maxArea = area; 
                        l++;
                } else {
                        r--;
                }
            }
            return maxArea;
    }
};

int main(int argc, char *argv[]){
        Solution solution;
        std::vector<int> arr = {1,8,6,2,5,4,8,3,7};
        std::cout << solution.maxArea(arr) << std::endl;
}
