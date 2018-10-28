#!/usr/bin/env python3


class Solution(object):
    def isHappy(self, n):
        x = n
        xs = set()
        while x != 1:
            y = 0
            while x != 0:
                k = int(x % 10)
                x = int(x / 10)
                y += k * k
            x = y
            if x in xs:
                return False
            xs.add(x)
        return True


if __name__ == '__main__':
    solution = Solution()
    print(solution.isHappy(19), True)
    print(solution.isHappy(2), True)
