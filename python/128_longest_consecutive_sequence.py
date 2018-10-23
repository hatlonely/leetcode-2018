#!/usr/bin/env python3


class Solution:
    def longestConsecutive(self, nums):
        numset = set()
        for num in nums:
            numset.add(num)
        longest = 0
        while numset:
            num = numset.pop()
            length = 1
            num1 = num - 1
            while num1 in numset:
                numset.remove(num1)
                num1 -= 1
                length += 1
            num2 = num + 1
            while num2 in numset:
                numset.remove(num2)
                num2 += 1
                length += 1
            longest = max(longest, length)
        return longest


if __name__ == '__main__':
    solution = Solution()
    print(solution.longestConsecutive([100, 4, 200, 1, 3, 2]), 4)
