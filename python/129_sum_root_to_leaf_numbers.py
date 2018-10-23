#!/usr/bin/env python3

from treenode import *


class Solution:
    def sumNumbersRecursive(self, root, curr, sum):
        curr = curr * 10 + root.val
        if root.left is None and root.right is None:
            sum[0] += curr
            return
        if root.left:
            self.sumNumbersRecursive(root.left, curr, sum)
        if root.right:
            self.sumNumbersRecursive(root.right, curr, sum)

    def sumNumbers(self, root):
        if root is None:
            return 0
        sum = [0]
        self.sumNumbersRecursive(root, 0, sum)
        return sum[0]


if __name__ == '__main__':
    solution = Solution()
    print(solution.sumNumbers(NewTree([4, 9, 0, 5, 1])), 1026)
