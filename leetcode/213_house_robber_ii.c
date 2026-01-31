#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int helper(int* nums, int numsSize) {
      // dont in-place tabulate original array to avoid issues
    int* dp = malloc(numsSize * sizeof(int));
    if (numsSize == 0) return 0;
    dp[0] = nums[0];
    for (int i = 0; i < numsSize; i++){
         if (i > 1){
         dp[i] = fmax((int)nums[i] + dp[i - 2], (int)dp[i - 1]);
        }
        if (i == 1){
            dp[i] = (int)fmax(nums[i], nums[i - 1]);
        }
    }
    int result = dp[numsSize - 1];
    free(dp);
    return result;
}

int betterHelper(int* nums, int numsSize){
    int twoAgo = 0, oneAgo = 0; 
    for (int i = 0; i < numsSize; i++){
        int current = fmax(nums[i] + twoAgo, oneAgo);
        twoAgo = oneAgo;
        oneAgo = current;
    }
    return oneAgo;
}

int rob(int* nums, int numsSize) {
   int firstSet = helper(&nums[0], numsSize - 1);
   int secondSet = helper(&nums[1], numsSize - 1);
   if (numsSize == 1) return nums[0];
   return fmax(firstSet, secondSet);
}

typedef struct { 
    int input[10];
    int size;
    int expected;
} TestCase;

int main(){
        TestCase tests[] = {
                {{ 2, 3, 2 }, 3, 3},
                {{ 1, 2, 3, 1}, 4, 4},
                {{ 1, 2, 3 }, 3, 3},
                {{ 2, 7, 9, 3, 1, 5, 8, 4, 6, 10 }, 10, 29}
        };
        
        int numTests = sizeof(tests) / sizeof(tests[0]);

        for (int i = 0; i < numTests; i++){
            int result = rob(tests[i].input, tests[i].size);
            printf("Test %d expected=%d actual=%d\n", i+1, tests[i].expected, result);
        }
}




