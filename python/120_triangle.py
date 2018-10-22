#!/usr/bin/env python3


class Solution:
    def minimumTotal(self, triangle):
        if not triangle:
            return 0
        totals = [triangle[0]]

        for i in range(1, len(triangle)):
            total = [totals[i - 1][0] + triangle[i][0]]
            for j in range(1, len(triangle[i]) - 1):
                total.append(
                    min(totals[i - 1][j], totals[i - 1][j - 1]) + triangle[i][j])
            total.append(totals[i - 1][i - 1] + triangle[i][i])
            totals.append(total)
        return min(totals[-1])


if __name__ == '__main__':
    print(Solution().minimumTotal([
        [2],
        [3, 4],
        [6, 5, 7],
        [4, 1, 8, 3]
    ]), 11)
