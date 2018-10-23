#!/usr/bin/env python3

import sys


class Solution:
    def maxProfit(self, prices):
        if not prices:
            return 0
        profits = []
        minPrice = sys.maxsize
        profit = 0
        for i in range(0, len(prices)):
            minPrice = min(minPrice, prices[i])
            profit = max(profit, prices[i] - minPrice)
            profits.append(profit)
        maxPrice = 0
        profit = 0
        for i in range(len(prices) - 1, 0, -1):
            maxPrice = max(maxPrice, prices[i])
            profit = max(profit, maxPrice - prices[i])
            profits[i - 1] += profit
        return max(profits)


if __name__ == '__main__':
    print(Solution().maxProfit([7, 1, 5, 3, 6, 4]), 7)
    print(Solution().maxProfit([3, 3, 5, 0, 0, 3, 1, 4]), 6)
    print(Solution().maxProfit([7, 6, 5, 4, 3, 2, 1]), 0)
    print(Solution().maxProfit([1, 2, 3, 4, 5]), 4)
    print(Solution().maxProfit([1]), 0)
    print(Solution().maxProfit([1, 2]), 1)
    print(Solution().maxProfit([1, 2, 3]), 2)
    print(Solution().maxProfit([3, 2, 6, 5, 0, 3]), 7)
