#!/usr/bin/env python3

import sys


class Solution:
    def maxProfit(self, prices):
        minPrice = sys.maxsize
        maxProfit = 0
        for price in prices:
            minPrice = min(minPrice, price)
            maxProfit = max(maxProfit, price - minPrice)
        return maxProfit


if __name__ == '__main__':
    print(Solution().maxProfit([7, 1, 5, 3, 6, 4]))
