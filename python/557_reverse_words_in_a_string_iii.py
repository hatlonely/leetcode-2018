#!/usr/bin/env python3


class Solution:
    def reverseWords(self, s):
        return ' '.join([i[::-1] for i in s.split(' ')])


if __name__ == '__main__':
    print(Solution().reverseWords("Let's take LeetCode contest"))
