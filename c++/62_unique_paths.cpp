#include <gtest/gtest.h>

class Solution {
   public:
    int uniquePaths(int m, int n) {
        auto nums = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            nums[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            nums[i][0] = 1;
            for (int j = 1; j < n; j++) {
                nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
            }
        }
        return nums[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testUniquePaths, case1) {
    Solution solution;
    EXPECT_EQ(solution.uniquePaths(3, 2), 3);
}