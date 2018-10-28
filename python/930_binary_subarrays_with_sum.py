#!/usr/bin/env python3


class Solution:
    def numSubarraysWithSum(self, nums, sum):
        count = 0
        idxs = [-1]
        for i in range(len(nums)):
            if nums[i] == 1:
                idxs.append(i)
        idxs.append(len(nums))
        if sum == 0:
            for i in range(0, len(idxs) - 1):
                n = idxs[i + 1] - idxs[i]
                count += int((n - 1) * n / 2)
        else:
            for i in range(1, len(idxs) - sum):
                j = i + sum
                m = (idxs[i] - idxs[i - 1])
                n = (idxs[j] - idxs[j - 1])
                count += m * n
        return count


if __name__ == '__main__':
    solution = Solution()
    print(solution.numSubarraysWithSum([1, 0, 1, 0, 1], 2), 4)
    print(solution.numSubarraysWithSum([1, 0, 1, 0, 1], 3), 1)
    print(solution.numSubarraysWithSum([1, 0, 1, 0, 1], 1), 8)
    print(solution.numSubarraysWithSum([1, 0, 1], 1), 4)
    print(solution.numSubarraysWithSum([1, 0, 0], 0), 3)
    print(solution.numSubarraysWithSum([0, 0, 0, 0, 0], 0), 15)
