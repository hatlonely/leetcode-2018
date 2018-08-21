#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        bool zx = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                zx = true;
                break;
            }
        }
        bool zy = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                zy = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zx) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (zy) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testSetMatrixZeroes, case1) {
    Solution solution;
    auto     matrix = std::vector<std::vector<int>>({
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    });
    solution.setZeroes(matrix);
    EXPECT_EQ(matrix, std::vector<std::vector<int>>({
                          {1, 0, 1},
                          {0, 0, 0},
                          {1, 0, 1},
                      }));
}

TEST(testSetMatrixZeroes, case2) {
    Solution solution;
    auto     matrix = std::vector<std::vector<int>>({
        {1, 1, 1},
        {0, 1, 2},
    });
    solution.setZeroes(matrix);
    EXPECT_EQ(matrix, std::vector<std::vector<int>>({
                          {0, 1, 1},
                          {0, 0, 0},
                      }));
}

TEST(testSetMatrixZeroes, case3) {
    Solution solution;
    auto     matrix = std::vector<std::vector<int>>({
        {1, 0},
    });
    solution.setZeroes(matrix);
    EXPECT_EQ(matrix, std::vector<std::vector<int>>({
                          {0, 0},
                      }));
}
