#!/usr/bin/env python3


class Solution:
    def singleNumber(self, nums):
        n = 0
        for num in nums:
            n ^= num
        return n


if __name__ == '__main__':
    solution = Solution()
    print(solution.singleNumber([2, 2, 1]), 1)
