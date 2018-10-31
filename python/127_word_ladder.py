#!/usr/bin/env python3


class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        wordSet = set(wordList)
        lastWords = set([beginWord])
        length = 1
        while lastWords and endWord not in lastWords:
            length += 1
            currWords = set()
            for word1 in lastWords.copy():
                for i in range(len(word1)):
                    for ch in 'abcdefghijklmnopqrstuvwxyz':
                        word2 = word1[:i] + ch + word1[i+1:]
                        if word2 in wordSet:
                            currWords.add(word2)
            wordSet -= currWords
            lastWords = currWords
        if not lastWords:
            return 0
        return length


if __name__ == '__main__':
    solution = Solution()
    print(solution.ladderLength(
        'hit',
        'cog',
        ["hot", "dot", "dog", "lot", "log", "cog"]
    ), 5)
