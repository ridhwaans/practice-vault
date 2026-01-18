#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
        bool wordBreak(string s, vector<string>& wordDict){
            vector<bool> canBreak(s.size() + 1, false);
            canBreak[0] = true;
            for (size_t i = 1; i <= s.size(); i++){
                for (int j = 0; j < wordDict.size(); j++){
                    if ((i - wordDict[j].size() >= 0) && canBreak[i - wordDict[j].size()]) {             
                        string sub = s.substr(i - wordDict[j].size(), wordDict[j].size());
                        if (canBreak[i - wordDict[j].size()] && 
                            sub.compare(wordDict[j]) == 0) { 
                            canBreak[i] = true;
                            break;
                        }
                    }
                }
            }
            return canBreak[s.size()];
        }
};

struct TestCase {
    string s;
    vector<string> wordDict;
    bool output;
};
int main(int argc, char** argv){
    Solution solution;
    vector<TestCase> testCases = {
    {"applepenapple", {"apple", "pen"}, true},
    {"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
   };
    for (const auto& testCase : testCases){
        cout << "input: \"" << testCase.s << "\" wordDict = [";
        for (int i = 0; i < testCase.wordDict.size(); i++){
                cout << "\"" << testCase.wordDict[i] << "\"";
                if (i != testCase.wordDict.size() - 1) cout << ", ";
        }
        vector<string> dictCopy = testCase.wordDict;
        cout << "] output: " << boolalpha << solution.wordBreak(testCase.s, dictCopy) << " expected: " << testCase.output << endl;
    }
}

