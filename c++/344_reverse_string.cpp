#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string reverseString(std::string str) {
        int m = str.length() - 1;
        int n = str.length() / 2;
        for (int i = 0; i < n; i++) {
            std::swap(str[i], str[m - i]);
        }
        return str;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.reverseString("123456789"), "987654321");
}