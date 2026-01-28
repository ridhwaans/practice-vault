#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int **backtrack(int *candidates, int candidateSize, int target, int *returnSize,
                int **returnColumnSizes, int start, int *cur, int curSize,
                int ***combinationSum) {
  if (target == 0) {
    *combinationSum =
        realloc(*combinationSum, (*returnSize + 1) * sizeof(int *));
    *returnColumnSizes =
        realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
    (*combinationSum)[*returnSize] = malloc(curSize * sizeof(int));
    for (int i = 0; i < curSize; i++) {
      (*combinationSum)[*returnSize][i] = cur[i];
    }
    (*returnColumnSizes)[*returnSize] = curSize;
    (*returnSize)++;
    return *combinationSum;
  }

  for (int i = start; i < candidateSize; i++) {
    if (candidates[i] > target) {
      break;
    }
    cur[curSize] = candidates[i];

    backtrack(candidates, candidateSize, target - candidates[i], returnSize,
              returnColumnSizes, i, cur, curSize + 1, combinationSum);
  }
  return *combinationSum;
}

int **combinationSum(int *candidates, int candidateSize, int target,
                     int *returnSize, int **returnColumnSizes) {
  *returnSize = 5;
  *returnColumnSizes = malloc(*returnSize * sizeof(int *));
  int **combinationSum = NULL;
  int *cur = malloc(target * sizeof(int));
  qsort(candidates, candidateSize, sizeof(int), cmp);

  backtrack(candidates, candidateSize, target, returnSize, returnColumnSizes, 0,
            cur, 0, &combinationSum);
  free(cur);
  return combinationSum;
}

int main() {
  int candidates[] = {2, 3, 6, 7};
  int target = 7;
  int returnSize;
  int *returnColumnSizes;

  int **result =
      combinationSum(candidates, 4, target, &returnSize, &returnColumnSizes);
  for (int i = 0; i < returnSize; i++) {
    printf("[");
    for (int j = 0; j < returnColumnSizes[i]; j++) {
      printf("%d", result[i][j]);
      if (j < returnColumnSizes[i] - 1)
        printf(", ");
    }
    printf("]\n");
    free(result[i]);
  }

  free(result);
  free(returnColumnSizes);
}
