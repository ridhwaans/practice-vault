int maxProfitQuadratic(int *prices, int pricesSize) {
  int max_profit = 0;
  for (int i = 0; i < pricesSize; i++) {
    for (int j = i; j < pricesSize; j++) {
      if (max_profit < (prices[j] - prices[i])) {
        max_profit = (prices[j] - prices[i]);
      }
    }
  }
  return max_profit;
}

int maxProfitLinear(int *prices, int pricesSize) {
  // kadanes algorithm
  int max_profit = 0;
  int buy = prices[0]; // buy at beginning

  for (int i = 1; i < pricesSize; i++) {
    if (prices[i] < buy) {
      buy = prices[i]; // lower price found. buy now
    } else if ((prices[i] - buy) > max_profit) {
      max_profit = prices[i] - buy; // update global
    }
  }
  return max_profit;
}

int maxProfit(int *prices, int pricesSize) {
  return maxProfitLinear(prices, pricesSize);
}
