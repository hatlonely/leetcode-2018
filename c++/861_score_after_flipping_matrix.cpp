#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
   public:
    int matrixScore(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] != 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (matrix[i][j] == 0);
            }
        }

        for (int j = 1; j < n; j++) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                count += (matrix[i][j] == 1);
            }
            if (count > m - count) {
                continue;
            }
            for (int i = 0; i < m; i++) {
                matrix[i][j] = (matrix[i][j] == 0);
            }
        }

        int score = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                score += 1 << (n - j - 1);
            }
        }

        return score;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     matrix = std::vector<std::vector<int>>{
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
    };
    EXPECT_EQ(solution.matrixScore(matrix), 39);
}