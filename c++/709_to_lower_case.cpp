#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string toLowerCase(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.toLowerCase("Love"), "love");
}