#!/usr/bin/env python3

nexts = [
    [4, 6],
    [6, 8],
    [7, 9],
    [4, 8],
    [3, 9, 0],
    [],
    [1, 7, 0],
    [2, 6],
    [1, 3],
    [2, 4],
]

M = 1000000007


class Solution:
    def knightDialer(self, n):
        if n == 1:
            return 10

        dp0 = [len(i) for i in nexts]
        for i in range(2, n):
            dp1 = [0 for i in range(10)]
            for j in range(10):
                for m in nexts[j]:
                    dp1[j] += dp0[m]
                    dp1[j] %= M
            dp0 = dp1
        return sum(dp0) % M


if __name__ == '__main__':
    solution = Solution()
    print(solution.knightDialer(1), 10)
    print(solution.knightDialer(2), 20)
    print(solution.knightDialer(3), 46)
    print(solution.knightDialer(4), 104)
    print(solution.knightDialer(5), 240)
    print(solution.knightDialer(200), 38950354)
    print(solution.knightDialer(161), 533302150)
    print(solution.knightDialer(3660), 685917436)
    print(solution.knightDialer(4947), 666534176)
    print(solution.knightDialer(50000), 973717386)
