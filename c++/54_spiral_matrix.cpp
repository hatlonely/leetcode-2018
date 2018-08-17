#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        std::vector<int> orders;
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int t = (std::min(m, n) + 1) / 2;
        orders.reserve(m * n);

        for (int i = 0; i < t; i++) {
            for (int j = i; j < n - i - 1; j++) {
                orders.push_back(matrix[i][j]);
            }
            for (int j = i; j < m - i - 1; j++) {
                orders.push_back(matrix[j][n - i - 1]);
            }
            if (m - i - 1 == i) {
                orders.push_back(matrix[i][n - i - 1]);
                break;
            }
            if (n - i - 1 == i) {
                orders.push_back(matrix[m - i - 1][i]);
                break;
            }
            for (int j = n - i - 1; j > i; j--) {
                orders.push_back(matrix[m - i - 1][j]);
            }
            for (int j = m - i - 1; j > i; j--) {
                orders.push_back(matrix[j][i]);
            }
        }

        return orders;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;

    EXPECT_EQ(
        solution.spiralOrder(
            {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}}),
        std::vector<int>({1, 2, 3, 6, 9, 8, 7, 4, 5}));

    EXPECT_EQ(
        solution.spiralOrder(
            {{1, 2},
             {3, 4}}),
        std::vector<int>({1, 2, 4, 3}));

    EXPECT_EQ(
        solution.spiralOrder(
            {{1, 2, 3}}),
        std::vector<int>({1, 2, 3}));

    EXPECT_EQ(
        solution.spiralOrder(
            {{1, 2, 3, 4}}),
        std::vector<int>({1, 2, 3, 4}));

    EXPECT_EQ(
        solution.spiralOrder(
            {{1}, {2}, {3}}),
        std::vector<int>({1, 2, 3}));

    EXPECT_EQ(
        solution.spiralOrder(
            {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12}}),
        std::vector<int>({1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));

    EXPECT_EQ(
        solution.spiralOrder(
            {{1, 2, 3},
             {4, 5, 6}}),
        std::vector<int>({1, 2, 3, 6, 5, 4}));
}
