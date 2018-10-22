#!/usr/bin/env python3


class Solution:
    def maxProfit(self, prices):
        m = 0
        for i in range(1, len(prices)):
            m += prices[i] - prices[i-1] if prices[i] > prices[i-1] else 0
        return m


if __name__ == '__main__':
    print(Solution().maxProfit([7, 1, 5, 3, 6, 4]), 7)
