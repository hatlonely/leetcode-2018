#!/usr/bin/env python3

import sys


class Solution(object):
    def maxProductWithoutZeros(self, nums):
        if not nums:
            return - sys.maxsize - 1
        if len(nums) == 1:
            return nums[0]
        l = 1
        m = 1
        r = 1
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i] < 0:
                break
            l *= nums[i]
            i += 1
        while i < j:
            if nums[j] < 0:
                break
            r *= nums[j]
            j -= 1
        for k in range(i + 1, j):
            m *= nums[k]

        if i == j:
            if nums[i] > 0:
                return l * nums[i]
            return max(l, r)

        l *= nums[i]
        r *= nums[j]
        if m > 0:
            return l * m * r
        else:
            return m * min(l, r)

    def maxProduct(self, nums):
        if not nums:
            return 0
        j = 0
        product = - sys.maxsize - 1
        for i in range(len(nums)):
            if nums[i] == 0:
                product = max(product, self.maxProductWithoutZeros(nums[j:i]))
                j = i + 1
        if j != 0:
            product = max(product, 0)
        product = max(product, self.maxProductWithoutZeros(nums[j:]))
        return product


if __name__ == '__main__':
    solution = Solution()
    print(solution.maxProduct([2, 3, -2, 4]), 6)
    print(solution.maxProduct([2, 3, -2]), 6)
    print(solution.maxProduct([-2, 4]), 4)
    print(solution.maxProduct([2, 4]), 8)
    print(solution.maxProduct([2, 3, 2, 4]), 48)
    print(solution.maxProduct([2, -1, 3, -2, 5, -3, 4]), 360)
    print(solution.maxProduct([-2, 0, -1]), 0)
    print(solution.maxProduct([0]), 0)
    print(solution.maxProduct([6, 3, -10, 0, 2]), 18)
