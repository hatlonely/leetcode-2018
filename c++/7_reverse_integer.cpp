#include <gtest/gtest.h>
#include <limits>

class Solution {
   public:
    int reverse(int x) {
        int64_t y = 0;
        while (x != 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (y > std::numeric_limits<int32_t>::max() || y < std::numeric_limits<int32_t>::min()) {
            return 0;
        }
        return y;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testReverseInteger, case1) {
    Solution solution;
    EXPECT_EQ(solution.reverse(10), 1);
    EXPECT_EQ(solution.reverse(123), 321);
    EXPECT_EQ(solution.reverse(-123), -321);
    EXPECT_EQ(solution.reverse(-2147483648), 0);
}
