#!/usr/bin/env python3


class Solution:
    def dfs(self, board, i, j, m, n):
        if board[i][j] != 'O':
            return
        board[i][j] = 'M'
        if i > 0:
            self.dfs(board, i - 1, j, m, n)
        if j > 0:
            self.dfs(board, i, j - 1, m, n)
        if i + 1 < m:
            self.dfs(board, i + 1, j, m, n)
        if j + 1 < n:
            self.dfs(board, i, j + 1, m, n)

    def solve(self, board):
        if not board or not board[0]:
            return
        m = len(board)
        n = len(board[0])
        for i in range(0, m):
            self.dfs(board, i, 0, m, n)
            self.dfs(board, i, n - 1, m, n)
        for j in range(0, n):
            self.dfs(board, 0, j, m, n)
            self.dfs(board, m - 1, j, m, n)
        for i in range(0, m):
            for j in range(0, n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == 'M':
                    board[i][j] = 'O'


if __name__ == '__main__':
    solution = Solution()
    board = [
        ['X', 'X', 'X', 'X'],
        ['X', 'O', 'O', 'X'],
        ['X', 'X', 'O', 'X'],
        ['X', 'O', 'X', 'X'],
    ]
    solution.solve(board)
    print(board)
