#include <stdlib.h>

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

int maxProfitBottomUpDP(int k, int *prices, int pricesSize) {
  /*
  if for (int k = 0; k < K; k++) then the max state you compute is K - 1,
  meaning you only allow K - 1 transactions, not K
  same case with pricesSize + 1 because recurrence looks one day ahead
  also watch for operator precedence bugs
  */
  int ***dp = malloc((pricesSize + 1) * sizeof(int **));
  for (int i = 0; i < pricesSize + 1; i++) {
    dp[i] = malloc(2 * sizeof(int *));
    for (int j = 0; j < 2; j++) {
      // mistake - garbage values because uninitialized
      // dp[i][j] = malloc((k + 1) * sizeof(int));
      dp[i][j] = calloc(k + 1, sizeof(int));
    }
  }

  // state 0 - not holding, can buy now and sell after
  // state 1 - bought before / holding, can sell now
  // MAX chooses between performing action or skipping
  // k means sells / transaction count. transaction completes when you sell
  // buying keeps k the same, selling uses k - 1

  // mistake - i = pricesSize - 2 loop skipped the last day
  // because pricesSize + 1 alloc means base case is dp[pricesSize][...][...] =
  // 0
  for (int i = pricesSize - 1; i >= 0; i--) {
    for (int j = 0; j <= k; j++) {
      dp[i][0][j] = MAX(-prices[i] + dp[i + 1][1][j], dp[i + 1][0][j]);
      // mistake - j-1 goes out of bounds when j = 0
      // dp[i][1][j] = MAX(prices[i] + dp[i+1][0][j], dp[i+1][1][j-1]);

      // mistake - holding state means bought before so sell now and buy later
      // from dp[i+1] but sell now did not substract k (consume one transaction)
      // dp[i][1][j] = prices[i] + dp[i+1][0][j];

      // skip, keep holding until out of bounds check
      dp[i][1][j] = dp[i + 1][1][j];
      if (j > 0) {
        dp[i][1][j] = MAX(prices[i] + dp[i + 1][0][j - 1], dp[i + 1][1][j]);
      }
    }
  }

  int result = dp[0][0][k];

  // mistake - dp[i][j][k] is an int, not a pointer. free/ dealloc pointers
  // mistake - if innermost arrays dp[i][j] are freed, freeing dp[i] and dp were
  // missed for (int i = 0; i < pricesSize; i++){
  //     for (int j = 0; j < k; j++){
  //         free(dp[i][1][j]);
  //         free(dp[i][0][j]);
  //     }
  // }

  // free order doesnt matter because dp[i][0] and dp[i][1] are separate
  // allocated arrays.
  for (int i = 0; i < pricesSize + 1; i++) {
    free(dp[i][0]);
    free(dp[i][1]);
    free(dp[i]);
  }
  free(dp);

  return result;
}

int maxProfit(int k, int *prices, int pricesSize) {
  return maxProfitBottomUpDP(k, prices, pricesSize);
}
