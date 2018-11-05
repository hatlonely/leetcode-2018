#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        int  m  = grid.size();
        auto vm = std::vector<int>(m, 0);
        auto hm = std::vector<int>(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                vm[i] = std::max(vm[i], grid[i][j]);
                hm[j] = std::max(hm[j], grid[i][j]);
            }
        }

        auto count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                count += std::min(vm[i], hm[j]) - grid[i][j];
            }
        }

        return count;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     grid = std::vector<std::vector<int>>({
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0},
    });
    EXPECT_EQ(solution.maxIncreaseKeepingSkyline(grid), 35);
}