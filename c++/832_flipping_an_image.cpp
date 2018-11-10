#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> flipAndInvertImage(
        std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            auto k = n / 2;
            for (int j = 0; j < k; j++) {
                std::swap(matrix[i][j], matrix[i][n - j - 1]);
            }
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (matrix[i][j] == 0);
            }
        }

        return matrix;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}