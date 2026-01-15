#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> bottomUp(amount + 1, INT_MAX);
       // index is amount, element is minCoins
       bottomUp[0] = 0;
        for (int i = 1;i<=amount; i++){
            for (int j = 0;j<coins.size();j++){
                // filters dont interfere with search for valid possibilities, just avoid out of bounds and overflow errors 
                if ((i - coins[j]) >= 0 && bottomUp[i - coins[j]] != INT_MAX){
                // not doing runningAmounts towards target because dont yet have higher amounts in bottom up 
                bottomUp[i] = std::min(bottomUp[i - coins[j]] + 1, bottomUp[i]);
                }
            }
        }
        return bottomUp[amount] != INT_MAX ? bottomUp[amount] : -1;
    }
};

struct TestCase {
    vector<int> coins;
    int amount;
    int expected;
};

int main(int argc, char **argv){
    Solution solution;
    vector<TestCase> testCases = {
            {{1,2,5}, 11, 3},
            {{2}, 3, -1},
            {{1}, 0, 0}
    };
    for (int i = 0; i < testCases.size(); i++){
        cout << "Test " << i+1 << ": coins: ";
        cout << "[";
        bool first = true;
        for (int x: testCases[i].coins){
                if (!first) cout << ", ";
                cout << x;
                first = false;
        }
        cout << "]";
        cout << " amount: " << testCases[i].amount << " actual: " << solution.coinChange(testCases[i].coins, testCases[i].amount) << " expected: " << testCases[i].expected << endl;
        }
}
