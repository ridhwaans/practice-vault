#include <limits.h>

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

int maxProfit(int *prices, int pricesSize) {
  int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
  for (int i = 0; i < pricesSize; i++) {
    s1 = MAX(s1, -prices[i]);
    s2 = MAX(s2, s1 + prices[i]);
    s3 = MAX(s3, s2 - prices[i]);
    s4 = MAX(s4, s3 + prices[i]);
  }
  return s4;
}
