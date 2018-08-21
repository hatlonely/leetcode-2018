#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int minPathSum(const std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int  m     = grid.size();
        int  n     = grid[0].size();
        auto sums  = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        sums[0][0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            sums[0][j] = sums[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            sums[i][0] = sums[i - 1][0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                sums[i][j] = std::min(sums[i - 1][j], sums[i][j - 1]) + grid[i][j];
            }
        }
        return sums[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.minPathSum(
                  {{1, 3, 1},
                   {1, 5, 1},
                   {4, 2, 1}}),
              7);
}