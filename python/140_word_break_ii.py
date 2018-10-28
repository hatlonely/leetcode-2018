#!/usr/bin/env python3


class Solution:
    def wordBreak(self, s, wordDict):
        if not wordDict:
            return []
        gp = {}
        dp = [True] + [False for i in range(len(s))]
        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    if i not in gp:
                        gp[i] = []
                    gp[i].append(j)
        print(gp)
        n = len(s)
        paths = []
        self.travel(gp, n, 0, [n], paths)
        result = []
        for path in paths:
            path = path[::-1]
            words = []
            for i in range(1, len(path)):
                words.append(s[path[i-1]:path[i]])
            result.append(' '.join(words))
        return result

    def travel(self, gp, s, e, path, paths):
        if s == e:
            paths.append(path.copy())
            return
        if s not in gp:
            return
        for i in gp[s]:
            path.append(i)
            self.travel(gp, i, e, path, paths)
            path.pop()


if __name__ == '__main__':
    solution = Solution()
    print(solution.wordBreak(
        "catsanddog",
        ["cat", "cats", "and", "sand", "dog"]
    ), [
        "cats and dog",
        "cat sand dog"
    ])

    print(solution.wordBreak(
        "catsandog",
        ["cats", "dog", "sand", "and", "cat"]
    ), [])
