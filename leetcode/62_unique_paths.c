#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    int** dp = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++){
        dp[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++){
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    int result = dp[m - 1][n - 1];
    free(dp);
    return result;
}

int main(int argc, char** argv){
    int testCases[2][2] = { {3,7}, {3, 2} };
    for (int i = 0; i < 2; i++){
            printf("m=%d, n=%d, output=%d\n", testCases[i][0], testCases[i][1], uniquePaths(testCases[i][0],testCases[i][1]));
    }
}
