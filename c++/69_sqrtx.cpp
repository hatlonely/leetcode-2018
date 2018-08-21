#include <gtest/gtest.h>
#include <limits>

class Solution {
   public:
    int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int l = 0;
        int r = x;

        while (l <= r) {
            int m = (l + r) / 2;
            int n = x / m;
            if (n > m) {
                l = m + 1;
            } else if (n < m) {
                r = m - 1;
            } else {
                return m;
            }
        }

        return r;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.mySqrt(9), 3);
    EXPECT_EQ(solution.mySqrt(8), 2);
    EXPECT_EQ(solution.mySqrt(3), 1);
    EXPECT_EQ(solution.mySqrt(2), 1);
    EXPECT_EQ(solution.mySqrt(1), 1);
    EXPECT_EQ(solution.mySqrt(0), 0);
}