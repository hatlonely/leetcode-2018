#!/usr/bin/env python3

from treenode import *
import sys


class Solution:
    def maxPathSumRecursive(self, root):
        if root is None:
            return 0, 0
        if root.left is None and root.right is None:
            return root.val, root.val
        if root.left is None:
            maxR, maxRR = self.maxPathSumRecursive(root.right)
            return max(maxR, maxRR + root.val, root.val), max(maxRR + root.val, root.val)
        if root.right is None:
            maxL, maxLR = self.maxPathSumRecursive(root.left)
            return max(maxL, maxLR + root.val, root.val), max(maxLR + root.val, root.val)
        maxL, maxLR = self.maxPathSumRecursive(root.left)
        maxR, maxRR = self.maxPathSumRecursive(root.right)
        return max(maxL, maxR, maxLR + maxRR + root.val, root.val, maxLR + root.val, maxRR + root.val), max(maxLR + root.val, maxRR + root.val, root.val)

    def maxPathSum(self, root):
        maxSum, _ = self.maxPathSumRecursive(root)
        return maxSum


if __name__ == '__main__':
    solution = Solution()
    # print(solution.maxPathSum(NewTree([-10, 9, 20, None, None, 15, 7])), 42)
    # print(solution.maxPathSum(NewTree([-3])), -3)
    # print(solution.maxPathSum(NewTree([1, 2])), 3)
    # print(solution.maxPathSum(NewTree([2, -1])), 2)
    print(solution.maxPathSum(NewTree([1, -2, 3])), 4)
