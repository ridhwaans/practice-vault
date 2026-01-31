#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int rob(int* nums, int numsSize) {
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

int main(int argc, char **argv){
    int numsSize = 4;
    int nums[] = { 1, 2, 3, 1 }; 

   printf("nums = [ "); 
    for (int i = 0; i < numsSize; i++){
            printf("%d", nums[i]);
            if (i < numsSize - 1) printf(", ");
    }
    printf(" ] Output: %d\n", rob(nums, numsSize));
}

