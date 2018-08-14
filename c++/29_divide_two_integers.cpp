#include <gtest/gtest.h>
#include <limits>

class Solution {
   public:
    int64_t divide64(int64_t a, int64_t b) {
        if (a < 0) {
            return -divide64(-a, b);
        }
        if (b < 0) {
            return -divide64(a, -b);
        }
        if (a < b) {
            return 0;
        }

        int64_t r = 1;
        int64_t c = b;
        while (a >= c + c) {
            c += c;
            r += r;
        }

        return r + divide64(a - c, b);
    }

    int divide(int a, int b) {
        auto r = divide64(a, b);
        if (r > std::numeric_limits<int32_t>::max()) {
            return std::numeric_limits<int32_t>::max();
        }
        return r;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testDivideTwoIntegers, case1) {
    Solution solution;
    EXPECT_EQ(solution.divide(10, 3), 3);
    EXPECT_EQ(solution.divide(7, -3), -2);
    EXPECT_EQ(solution.divide(-2147483648, -1), 2147483647);
}
