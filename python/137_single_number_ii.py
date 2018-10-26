#!/usr/bin/env python3


class Solution:
    def singleNumber(self, nums):
        val0 = 0
        val1 = 0
        for num in nums:
            val0 = (val0 ^ num) & ~val1
            val1 = (val1 ^ num) & ~val0
        return val0 | val1


if __name__ == '__main__':
    solution = Solution()
    print(solution.singleNumber([2, 2, 3, 2]), 3)
