#!/usr/bin/env python3


class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        edges = dict()
        wordList.append(beginWord)
        level = {beginWord: 0}
        wordSet = set(wordList)
        lastWords = set([beginWord])
        levelidx = 0
        while endWord not in level and lastWords:
            levelidx += 1
            currWords = set()
            wordSet -= lastWords
            for word1 in lastWords.copy():
                for i in range(len(word1)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        word2 = word1[0:i] + c + word1[i+1:]
                        if word2 in wordSet:
                            level[word2] = levelidx
                            if word1 not in edges:
                                edges[word1] = set()
                            edges[word1].add(word2)
                            currWords.add(word2)
            lastWords = currWords
        paths = []
        self.travel(edges, beginWord, endWord, [beginWord], level, 1, paths)
        return paths

    def travel(self, edges, s, e, path, level, k, paths):
        if s == e:
            paths.append(path.copy())
        elif s not in edges:
            return
        else:
            for i in edges[s]:
                if i in level and level[i] == k:
                    path.append(i)
                    self.travel(edges, i, e, path, level, k+1, paths)
                    path.pop()


if __name__ == '__main__':
    solution = Solution()
    print(solution.findLadders(
        'hit',
        'cog',
        ["hot", "dot", "dog", "lot", "log", "cog"]
    ), [
        ["hit", "hot", "dot", "dog", "cog"],
        ["hit", "hot", "lot", "log", "cog"]
    ])
