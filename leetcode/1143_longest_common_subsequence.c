#include <stdlib.h> // for malloc, calloc, free
#include <string.h> // for strlen
#include <stdio.h> // for printf

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1);
    int n = strlen(text2);
    
    int **bottomUp =  (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++){
            bottomUp[i] = (int *) calloc((n + 1), sizeof(int));
    }
    for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (text1[i - 1] == text2[j - 1]){
                        bottomUp[i][j] = bottomUp[i - 1][j - 1] + 1;
                } else {
                    bottomUp[i][j] =  (bottomUp[i][j - 1] > bottomUp[i - 1][j])
                                ? bottomUp[i][j - 1] : bottomUp[i - 1][j];
                }
            }
    }
    int result = bottomUp[m][n];

    for (int i = 0; i <= m; i++){
        free(bottomUp[i]);
    }
    free(bottomUp);
    
    return result;
}

struct TestCase{
    char* text1;
    char* text2;
    int expected;
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main(int argc, char **argv){
        char text1[] = "cabd";
        char text2[] = "bd";
        int result = longestCommonSubsequence(text1, text2);
        struct TestCase testCases[]= {
                {"acde","ace",3},
                {"abc","abc",3},
                {"abc","def",0},
                {"mn", "moonyy",2},
        };

        for (int i =0;i < ARRAY_SIZE(testCases); i++){
            printf("text1: %s text2: %s expected: %d actual: %d\n", 
                            testCases[i].text1, 
                            testCases[i].text2, 
                            testCases[i].expected, 
                            longestCommonSubsequence(testCases[i].text1, testCases[i].text2));
        }

}
