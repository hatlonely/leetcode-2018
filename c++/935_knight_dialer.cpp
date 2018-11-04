#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <vector>

const static auto nexts = std::vector<std::vector<int>>({
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {1, 7, 0},
    {2, 6},
    {1, 3},
    {2, 4},
});

class Solution {
    const static int M = 1000000007;

   public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        auto dp0 = std::vector<int>(10, 0);
        for (int i = 0; i < 10; i++) {
            dp0[i] = nexts[i].size();
        }

        for (int i = 2; i < n; i++) {
            auto dp1 = std::vector<int>(10, 0);
            for (int j = 0; j < 10; j++) {
                for (auto m : nexts[j]) {
                    dp1[j] += dp0[m];
                    dp1[j] %= M;
                }
            }
            std::swap(dp0, dp1);
        }

        int sum = 0;
        for (auto i : dp0) {
            sum += i;
            sum %= M;
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.knightDialer(1), 10);
    EXPECT_EQ(solution.knightDialer(2), 20);
    EXPECT_EQ(solution.knightDialer(3), 46);
    EXPECT_EQ(solution.knightDialer(5), 240);
    EXPECT_EQ(solution.knightDialer(200), 38950354);
    EXPECT_EQ(solution.knightDialer(161), 533302150);
    EXPECT_EQ(solution.knightDialer(3660), 685917436);
    EXPECT_EQ(solution.knightDialer(4947), 666534176);
    EXPECT_EQ(solution.knightDialer(50000), 973717386);
}