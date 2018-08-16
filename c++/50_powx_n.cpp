#include <gtest/gtest.h>
#include <limits>

class Solution {
   public:
    double myPow64(double x, int64_t n) {
        if (n < 0) {
            return 1 / myPow64(x, -n);
        }
        double r = 1.0;
        while (n != 0) {
            int64_t i = 1;
            double  y = x;
            while (i + i < n) {
                i += i;
                y *= y;
            }
            r *= y;
            n -= i;
        }

        return r;
    }

    double myPow(double x, int n) {
        return myPow64(x, n);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_DOUBLE_EQ(solution.myPow(2.0, 10), 1024.0);
    EXPECT_DOUBLE_EQ(solution.myPow(2.0, 3), 8.0);
    EXPECT_DOUBLE_EQ(solution.myPow(0.00001, 2147483647), 0);
}