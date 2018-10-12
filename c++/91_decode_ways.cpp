#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
   public:
    int numDecodings(const std::string& str) {
        int              len = str.length();
        std::vector<int> nums(len + 1, 0);
        nums[len]     = 1;
        nums[len - 1] = (str[len - 1] != '0');
        for (int i = len - 2; i >= 0; i--) {
            if (str[i] == '0') {
                nums[i] = 0;
            } else if (str[i] == '1' || (str[i] == '2' && str[i + 1] < '7')) {
                nums[i] = nums[i + 1] + nums[i + 2];
            } else {
                nums[i] = nums[i + 1];
            }
        }

        return nums[0];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.numDecodings("12"), 2);
    EXPECT_EQ(solution.numDecodings("226"), 3);
}