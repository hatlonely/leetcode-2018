#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        auto matrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        int  m      = 1;
        int  x      = 0;
        int  y      = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                matrix[x][y++] = m++;
            }
            for (int j = i; j < n - i - 1; j++) {
                matrix[x++][y] = m++;
            }
            for (int j = i; j < n - i - 1; j++) {
                matrix[x][y--] = m++;
            }
            for (int j = i; j < n - i - 1; j++) {
                matrix[x--][y] = m++;
            }
            x++;
            y++;
        }
        if (n % 2 == 1) {
            matrix[x][y] = m++;
        }

        return matrix;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testSpiralMatrixII, case1) {
    Solution solution;
    EXPECT_EQ(solution.generateMatrix(1), std::vector<std::vector<int>>({{1}}));
}

TEST(testSpiralMatrixII, case2) {
    Solution solution;
    EXPECT_EQ(solution.generateMatrix(2), std::vector<std::vector<int>>({{1, 2}, {4, 3}}));
}

TEST(testSpiralMatrixII, case3) {
    Solution solution;
    EXPECT_EQ(solution.generateMatrix(3), std::vector<std::vector<int>>({{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}));
}