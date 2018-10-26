#!/usr/bin/env python3


class Solution:
    def minCut(self, s):
        cuts = [-1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            cuts[i] = cuts[i - 1] + 1
            for j in range(0, i - 1):
                if s[j:i] == s[j:i][::-1]:
                    cuts[i] = min(cuts[i], cuts[j] + 1)
        return cuts[len(s)]


if __name__ == '__main__':
    solution = Solution()
    print(solution.minCut('aabaaaca'), 1)
