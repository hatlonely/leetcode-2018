#!/usr/bin/env python3

import sys


class Solution:
    def minFallingPathSum(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        if n == 1:
            return matrix[0][0]
        dp = [[0 for i in range(m)] for j in range(n)]
        for j in range(n):
            dp[0][j] = matrix[0][j]
        for i in range(1, m):
            dp[i][0] = min(
                dp[i-1][0], dp[i-1][1]
            ) + matrix[i][0]
            for j in range(1, n-1):
                dp[i][j] = min(
                    dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]
                ) + matrix[i][j]
            dp[i][n-1] = min(
                dp[i-1][n-1], dp[i-1][n-2]
            ) + matrix[i][n-1]
        return min(dp[n-1])


if __name__ == '__main__':
    solution = Solution()
    print(solution.minFallingPathSum([
        [1, 2, 3], [4, 5, 6], [7, 8, 9]
    ]), 12)
    print(solution.minFallingPathSum([
        [10]
    ]), 10)
    print(solution.minFallingPathSum([
        [17, 82], [1, -44]
    ]), 10)
