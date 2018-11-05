#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.canWinNim(1));
    EXPECT_FALSE(solution.canWinNim(4));
}
