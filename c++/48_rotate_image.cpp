#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int m                        = matrix[i][j];
                matrix[i][j]                 = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i]         = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i]         = m;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;

    auto matrix = std::vector<std::vector<int>>({{1, 2, 3},
                                                 {4, 5, 6},
                                                 {7, 8, 9}});

    auto result = std::vector<std::vector<int>>({{7, 4, 1},
                                                 {8, 5, 2},
                                                 {9, 6, 3}});

    solution.rotate(matrix);
    EXPECT_EQ(matrix, result);
}