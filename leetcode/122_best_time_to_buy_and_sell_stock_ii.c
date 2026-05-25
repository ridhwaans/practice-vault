int maxProfitWhileLoop(int *prices, int pricesSize) {
  int lo, hi;
  int i = 0, profits = 0;
  while (i < pricesSize - 1) {
    while (i < pricesSize - 1 && prices[i] >= prices[i + 1]) {
      i++;
    }
    lo = prices[i];
    while (i < pricesSize - 1 && prices[i] <= prices[i + 1]) {
      i++;
    }
    hi = prices[i];
    profits += hi - lo;
  }
  return profits;
}

int maxProfitForLoop(int *prices, int pricesSize) {
  int profit = 0;
  for (int i = 1; i < pricesSize; i++) {
    if (prices[i - 1] < prices[i]) {
      profit += prices[i] - prices[i - 1];
    }
  }
  return profit;
}

int maxProfit(int *prices, int pricesSize) {
  return maxProfitWhileLoop(prices, pricesSize);
}
