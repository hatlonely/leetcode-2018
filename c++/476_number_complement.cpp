#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int findComplement(int num) {
        int i = 0;
        while (num >> i != 0) {
            i++;
        }
        int k = 32 - i;
        return (~num << k) >> k;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.findComplement(5), 2);
    EXPECT_EQ(solution.findComplement(1), 0);
    EXPECT_EQ(solution.findComplement(7), 0);
    EXPECT_EQ(solution.findComplement(4), 3);
}
