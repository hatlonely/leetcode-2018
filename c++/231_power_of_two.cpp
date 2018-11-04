#include <gtest/gtest.h>
#include <iostream>
#include <numeric>

class Solution {
   public:
    bool isPowerOfTwo(int n) {
        if (n == 0 || n == std::numeric_limits<int>::min()) {
            return false;
        }
        return (n & n - 1) == 0;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isPowerOfTwo(32));
}