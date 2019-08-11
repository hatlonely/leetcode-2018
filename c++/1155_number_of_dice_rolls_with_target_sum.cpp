#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int numRollsToTarget(int d, int f, int target) {
        std::vector<std::vector<int>> v(d + 1, std::vector<int>(target + 1, 0));
        for (int i = 1; i <= f && i <= target; i++) {
            v[1][i] = 1;
        }
        for (int i = 2; i <= d; i++) {
            for (int j = i; j <= target && j <= i * f; j++) {
                for (int k = 1; k <= f; k++) {
                    if (j - k > 0) {
                        v[i][j] += v[i - 1][j - k];
                        v[i][j] %= 1000000007;
                    }
                }
            }
        }

        return v[d][target];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.numRollsToTarget(1, 6, 3), 1);
    EXPECT_EQ(solution.numRollsToTarget(2, 6, 7), 6);
    EXPECT_EQ(solution.numRollsToTarget(2, 5, 10), 1);
    EXPECT_EQ(solution.numRollsToTarget(1, 2, 3), 0);
    EXPECT_EQ(solution.numRollsToTarget(30, 30, 500), 222616187);
}