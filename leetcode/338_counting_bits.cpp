#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
       int offset = 1;
      for (int i = 1; i <= n; i++){
        if (offset * 2 == i){
                offset = i;
        }
        dp[i] = 1 + dp[i - offset]; 
      } 
      return dp;
    }
};

int main(int argc, char *argv[]){
        Solution solution;
        vector<int> case2 = solution.countBits(5);
        cout << "input n = 5" << "\n";
        cout << "output" << "\n[";
        for (size_t i = 0; i < case2.size(); i++) {
            cout << case2[i];
            if (i + 1 < case2.size()) cout << ", ";
         }
        cout << "]";
}
