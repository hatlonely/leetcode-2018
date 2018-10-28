#!/usr/bin/env python3


class Solution(object):
    def reverseWords(self, s):
        return ' '.join([w for w in s.split()][::-1])


if __name__ == '__main__':
    solution = Solution()
    print(solution.reverseWords("the sky is blue"), "blue is sky the")
    print(solution.reverseWords(""), "")
    print(len(solution.reverseWords("  ")), 0)
