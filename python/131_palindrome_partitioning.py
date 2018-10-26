#!/usr/bin/env python3


class Solution:
    def partition(self, s):
        if len(s) == 0:
            return [[]]
        if len(s) == 1:
            return [[s]]
        result = []
        for i in range(1, len(s)+1):
            if s[:i] == s[:i][::-1]:
                ps = self.partition(s[i:])
                for p in ps:
                    p.insert(0, s[:i])
                    result.append(p)
        return result


if __name__ == '__main__':
    solution = Solution()
    print(solution.partition('aab'))
    print(solution.partition('bb'))
