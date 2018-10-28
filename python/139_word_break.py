#!/usr/bin/env python3


class Solution:
    def wordBreak(self, s, wordDict):
        if not wordDict:
            return s is None
        dp = [True] + [False for i in range(len(s))]
        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break
        return dp[len(dp) - 1]


if __name__ == '__main__':
    solution = Solution()
    print(solution.wordBreak("leetcode", ["leet", "code"]), True)
    print(solution.wordBreak(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        ["aaa", "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa",
            "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"]
    ), False)
    print(solution.wordBreak(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        ["aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa",
            "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "ba"],
    ), False)
