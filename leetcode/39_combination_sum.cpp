#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    void bt(vector<int>& candidates, int target, int currentIndex, vector<int>& currentList, vector<vector<int>>& combinations){
        if (target < 0) {
           return;         
        }
        if (target == 0){
                combinations.push_back(currentList);
                return;
                
        }
        for (int i = currentIndex; i < candidates.size(); i++){
            currentList.push_back(candidates[i]); //push_back mutates the container but does not return it so cannot use inline
            bt(candidates, target - candidates[i], i, currentList, combinations);
            currentList.pop_back();
            // bt(candidates, target, i + 1, currentList, combinations);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> currentList;
        
        bt(candidates, target, 0, currentList, combinations);
        return combinations;
    }
};

int main(int argc, char **argv){
 cout << "candidates = [ ";
 vector<int> candidates { 2, 3, 6, 7 };
 int target = 7;
 bool first = true;
 for (const auto& candidate : candidates){
    if (!first) cout << ", ";
    cout << candidate;
    first = false;
 }
 cout << "] target = " << target << endl;

 Solution solution;
 vector<vector<int>> combinations = solution.combinationSum(candidates, target);
    cout << "[";
    for (size_t i = 0; i < combinations.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < combinations[i].size(); j++) {
            cout << combinations[i][j];
            if (j + 1 < combinations[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < combinations.size()) cout << ",";
    }
    cout << "]" << endl;
}
