#!/usr/bin/env python3


class Solution:
    def isPalindrome(self, s):
        s = ''.join([c for c in s if c.isalnum()]).lower()
        return s == s[::-1]


if __name__ == '__main__':
    solution = Solution()
    print(solution.isPalindrome('A man, a plan, a canal: Panama'), True)
