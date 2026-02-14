#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int topDown( int i, char* word){
    // base cases
    if (i == strlen(word)) return 1;
    if (word[i] == '0') return 0;

    int count = topDown(i + 1, word);

    if ((i + 1) <= strlen(word) - 1){
        int doubleDigit = (((word[i] - '0') * 10) + (word[i+1] - '0'));
        if (doubleDigit >= 10 && doubleDigit <= 26){
            count += topDown(i + 2, word);
        }
    }
    return count;
};

int bottomUp(char* s){
        if (s == NULL || strlen(s) == 0) return 0;
        int dp[2] = { 1, 0 }; // dp[0] = ways before start, dp[1]=ways at index 0

        if ((s[0] - '0') > 0){
            dp[1] = 1;
        } else {
            return 0;
        }
        int i = 1;
        while (s[i] != '\0'){
                int cur = 0;
                if ((s[i] - '0') > 0) {
                        cur += dp[1];
                }
                int val = (s[i-1]-'0')*10 + (s[i]-'0');
                if (val >= 10 && val <= 26){
                        cur += dp[0];
                }

                dp[0] = dp[1];
                dp[1] = cur;
                i++;
        }
   return dp[1];
}

int numDecodings(char* s){
    //return topDown(0, s);
    return bottomUp(s);
}
