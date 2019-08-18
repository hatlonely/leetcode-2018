#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int maxDistance(std::vector<std::vector<int>>& g) {
        std::vector<std::vector<int>> grid(g);
        auto                          n     = grid.size();
        auto                          count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        if (count == n * n || count == 0) {
            return -1;
        }
        for (int k = 1;; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == k) {
                        if (i - 1 >= 0 && grid[i - 1][j] == 0) {
                            grid[i - 1][j] = k + 1;
                            count--;
                        }
                        if (i + 1 < n && grid[i + 1][j] == 0) {
                            grid[i + 1][j] = k + 1;
                            count--;
                        }
                        if (j - 1 >= 0 && grid[i][j - 1] == 0) {
                            grid[i][j - 1] = k + 1;
                            count--;
                        }
                        if (j + 1 < n && grid[i][j + 1] == 0) {
                            grid[i][j + 1] = k + 1;
                            count--;
                        }
                        if (count == 0) {
                            return k;
                        }
                    }
                }
            }
        }

        return 0;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case5053) {
    Solution solution;
    {
        auto grid = std::vector<std::vector<int>>{
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1},
        };
        EXPECT_EQ(solution.maxDistance(grid), 2);
    }
    {
        auto grid = std::vector<std::vector<int>>{
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        EXPECT_EQ(solution.maxDistance(grid), 4);
    }
    {
        auto grid = std::vector<std::vector<int>>{
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        EXPECT_EQ(solution.maxDistance(grid), -1);
    }
}
