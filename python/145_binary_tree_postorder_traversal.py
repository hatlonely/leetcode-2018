#!/usr/bin/env python3

from treenode import *

class Solution:
    def postorderTraversal(self, root):
        if root is None:
            return []
        return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val]

if __name__ == '__main__':
    solution = Solution()
    print(solution.postorderTraversal(NewTree([1, None, 2, 3])))