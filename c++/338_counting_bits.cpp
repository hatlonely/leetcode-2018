#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> countBits(int num) {
        num++;
        auto bits = std::vector<int>(num, 0);
        bits[0]   = 0;
        int m     = 1;
        while (m < num) {
            for (int i = 0; i < m && i + m < num; i++) {
                bits[i + m] = bits[i] + 1;
            }
            m += m;
        }
        return bits;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.countBits(5), std::vector<int>({0, 1, 1, 2, 1, 2}));
    EXPECT_EQ(solution.countBits(4), std::vector<int>({0, 1, 1, 2, 1}));
    EXPECT_EQ(solution.countBits(2), std::vector<int>({0, 1, 1}));
    EXPECT_EQ(solution.countBits(0), std::vector<int>({0}));
}
