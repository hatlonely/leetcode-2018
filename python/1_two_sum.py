
#!/usr/bin/env python3


class Solution:
    def twoSum(self, nums, target):
        numIdxMap = {}
        for i in range(0, len(nums)):
            if target - nums[i] in numIdxMap:
                return [i, numIdxMap[target - nums[i]]]
            numIdxMap[nums[i]] = i
        return [-1, -1]


if __name__ == '__main__':
    print(Solution().twoSum([2, 7, 11, 15], 9), [0, 1])
