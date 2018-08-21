#include <gtest/gtest.h>

class Solution {
   public:
    int climbStairs(int n) {
        static auto fab = std::vector<int>({1, 1, 2});
        if (n < fab.size()) {
            return fab[n];
        }
        fab.reserve(n + 1);
        for (int i = fab.size(); i <= n; i++) {
            fab.emplace_back(fab[i - 1] + fab[i - 2]);
        }

        return fab[n];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.climbStairs(2), 2);
    EXPECT_EQ(solution.climbStairs(3), 3);
}