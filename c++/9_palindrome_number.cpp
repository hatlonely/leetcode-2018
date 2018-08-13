#include <gtest/gtest.h>

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int y = 0;
        int t = x;
        while (t != 0) {
            y *= 10;
            y += t % 10;
            t /= 10;
        }

        return x == y;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testPalindromeNumber, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isPalindrome(121));
    EXPECT_FALSE(solution.isPalindrome(-121));
    EXPECT_FALSE(solution.isPalindrome(10));
}
