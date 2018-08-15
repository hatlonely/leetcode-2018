#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    bool solveSudokuRecursive(
        std::vector<std::vector<char>>& sudoku,
        std::vector<std::bitset<9>>&    bsRows,
        std::vector<std::bitset<9>>&    bsCols,
        std::vector<std::bitset<9>>&    bsBlks,
        int                             pos) {
        for (; pos < 81; pos++) {
            if (sudoku[pos / 9][pos % 9] == '.') {
                break;
            }
        }
        if (pos >= 81) {
            return true;
        }
        int i = pos / 9;
        int j = pos % 9;

        for (int k = 0; k < 9; k++) {
            if (bsRows[i].test(k)) {
                continue;
            }
            if (bsCols[j].test(k)) {
                continue;
            }
            if (bsBlks[i / 3 * 3 + j / 3].test(k)) {
                continue;
            }
            sudoku[i][j] = k + '1';
            bsRows[i].set(k);
            bsCols[j].set(k);
            bsBlks[i / 3 * 3 + j / 3].set(k);
            if (solveSudokuRecursive(sudoku, bsRows, bsCols, bsBlks, i * 9 + j + 1)) {
                return true;
            }
            bsRows[i].set(k, false);
            bsCols[j].set(k, false);
            bsBlks[i / 3 * 3 + j / 3].set(k, false);
        }
        sudoku[i][j] = '.';

        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& sudoku) {
        std::vector<std::bitset<9>> bsRows(9);
        std::vector<std::bitset<9>> bsCols(9);
        std::vector<std::bitset<9>> bsBlks(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] == '.') {
                    continue;
                }
                bsRows[i].set(sudoku[i][j] - '1');
                bsCols[j].set(sudoku[i][j] - '1');
                bsBlks[i / 3 * 3 + j / 3].set(sudoku[i][j] - '1');
            }
        }

        solveSudokuRecursive(sudoku, bsRows, bsCols, bsBlks, 0);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;

    auto sudoku = std::vector<std::vector<char>>(
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '.', '2', '8'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}});
    auto result = std::vector<std::vector<char>>(
        {{'5', '3', '2', '6', '7', '8', '9', '1', '4'},
         {'6', '7', '4', '1', '9', '5', '3', '8', '2'},
         {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
         {'8', '1', '9', '7', '6', '4', '2', '5', '3'},
         {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
         {'7', '5', '3', '9', '2', '1', '8', '4', '6'},
         {'9', '6', '1', '5', '3', '7', '4', '2', '8'},
         {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
         {'3', '4', '5', '2', '8', '6', '1', '7', '9'}});

    solution.solveSudoku(sudoku);
    EXPECT_EQ(sudoku, result);
}