#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class Solution {
   public:
    int surfaceArea(const vector<vector<int>>& grid) {
        int m    = grid.size();
        int n    = grid[0].size();
        int area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                area += grid[i][j] * 4 + 2;
                if (j + 1 < n) {
                    area -= std::min(grid[i][j], grid[i][j + 1]);
                }
                if (j - 1 >= 0) {
                    area -= std::min(grid[i][j], grid[i][j - 1]);
                }
                if (i + 1 < m) {
                    area -= std::min(grid[i][j], grid[i + 1][j]);
                }
                if (i - 1 >= 0) {
                    area -= std::min(grid[i][j], grid[i - 1][j]);
                }
            }
        }

        return area;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.surfaceArea({{2}}), 10);
    EXPECT_EQ(solution.surfaceArea({{1, 2}, {3, 4}}), 34);
    EXPECT_EQ(solution.surfaceArea({{1, 0}, {0, 2}}), 16);
}