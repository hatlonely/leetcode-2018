#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int maxTurbulenceSize(const std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int  maxLen = 1;
        bool gtlt   = false;
        bool start  = false;
        int  len    = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (!start) {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
                gtlt  = nums[i] > nums[i + 1];
                len   = 2;
                start = true;
                continue;
            }
            if (nums[i] == nums[i + 1]) {
                maxLen = std::max(len, maxLen);
                start  = false;
                continue;
            }
            if (nums[i] > nums[i + 1] == gtlt) {
                maxLen = std::max(len, maxLen);
                len    = 2;
                continue;
            }
            len++;
            gtlt = !gtlt;
        }
        maxLen = std::max(len, maxLen);

        return maxLen;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.maxTurbulenceSize({9, 4, 2, 10, 7, 8, 8, 1, 9}), 5);
    EXPECT_EQ(solution.maxTurbulenceSize({4, 8, 12, 16}), 2);
    EXPECT_EQ(solution.maxTurbulenceSize({0, 1, 1, 0, 1, 0, 1, 1, 0, 0}), 5);
    EXPECT_EQ(solution.maxTurbulenceSize({0, 8, 45, 88, 48, 68, 28, 55, 17, 24}), 8);
}