#include <gtest/gtest.h>

class Solution {
   public:
    int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int  m     = obstacleGrid.size();
        int  n     = obstacleGrid[0].size();
        auto nums  = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        nums[0][0] = obstacleGrid[0][0] == 0;
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                nums[0][j] = nums[0][j - 1];
            }
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                nums[i][0] = nums[i - 1][0];
            }
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
                }
            }
        }

        return nums[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.uniquePathsWithObstacles({
                  {0, 0, 0},
                  {0, 1, 0},
                  {0, 0, 0},
              }),
              2);

    EXPECT_EQ(solution.uniquePathsWithObstacles({
                  {0},
                  {0},
                  {0},
                  {0},
                  {0},
                  {0},
                  {0},
                  {0},
              }),
              1);
}