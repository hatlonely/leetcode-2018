#include <gtest/gtest.h>
#include <string>
#include <vector>

class Solution {
    bool existRecursive(
        const std::vector<std::vector<char>>& board,
        const std::string&                    word,
        int m, int n, int i, int j, int k,
        std::vector<std::vector<bool>>& visit) {
        if (visit[i][j] || word[k] != board[i][j]) {
            return false;
        }
        if (k + 1 == word.length()) {
            return true;
        }
        visit[i][j] = true;
        if (i < m - 1 && existRecursive(board, word, m, n, i + 1, j, k + 1, visit)) {
            return true;
        }
        if (i > 0 && existRecursive(board, word, m, n, i - 1, j, k + 1, visit)) {
            return true;
        }
        if (j < n - 1 && existRecursive(board, word, m, n, i, j + 1, k + 1, visit)) {
            return true;
        }
        if (j > 0 && existRecursive(board, word, m, n, i, j - 1, k + 1, visit)) {
            return true;
        }
        visit[i][j] = false;
        return false;
    }

   public:
    bool exist(const std::vector<std::vector<char>>& board, const std::string& word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int  m     = board.size();
        int  n     = board[0].size();
        auto visit = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (existRecursive(board, word, m, n, i, j, 0, visit)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     board = std::vector<std::vector<char>>({
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    });
    EXPECT_TRUE(solution.exist(board, "ABCCED"));
    EXPECT_TRUE(solution.exist(board, "SEE"));
    EXPECT_FALSE(solution.exist(board, "ABCB"));
}

TEST(test, case2) {
    Solution solution;
    auto     board = std::vector<std::vector<char>>({{'a'}});
    EXPECT_TRUE(solution.exist(board, "a"));
}