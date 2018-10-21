#!/usr/bin/env python3


class Solution:
    def getRow(self, n):
        if n == 0:
            return [1]
        row = self.getRow(n - 1)
        return [1] + [row[i] + row[i+1] for i in range(0, len(row) - 1)] + [1]


if __name__ == '__main__':
    print(Solution().getRow(3), [1, 3, 3, 1])
