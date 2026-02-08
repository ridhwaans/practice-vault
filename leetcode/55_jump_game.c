#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int target = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--){
        if (i + nums[i] >= target){
            target = i;
        }
    }
    return target == 0;
}

int main(int argc, char** argv){

    int nums[2][5] = {{2, 3, 1, 1, 4}, {3, 2, 1, 0, 4}};
    printf("#55 jump game\n");
    printf("case 1: %d\n", canJump(nums[0], 5));
    printf("case 2: %d\n", canJump(nums[1], 5)); 
}
