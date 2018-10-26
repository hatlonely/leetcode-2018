#!/usr/bin/env python3

import sys


class Solution:
    def canCompleteCircuit(self, gas, cost):
        sum = 0
        min = sys.maxsize
        idx = 0
        for i in range(0, len(gas)):
            sum += gas[i] - cost[i]
            if min > sum:
                min = sum
                idx = i
        return -1 if sum < 0 else (idx + 1) % len(gas)


if __name__ == '__main__':
    solution = Solution()
    print(solution.canCompleteCircuit([2, 3, 4, 5, 1], [4, 5, 1, 2, 3]), 2)
    print(solution.canCompleteCircuit([3, 1, 1], [1, 2, 2]), 0)
