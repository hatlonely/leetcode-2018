#!/usr/bin/env python3

from treenode import *


class Solution:
    def preorderTraversal(self, root):
        if root is None:
            return []
        return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)


if __name__ == '__main__':
    solution = Solution()
    print(solution.preorderTraversal(NewTree([1, None, 2, 3])))
