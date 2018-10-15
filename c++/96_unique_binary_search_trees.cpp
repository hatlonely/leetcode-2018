#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    thread_local static std::vector<int> nums;

   public:
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < nums.size()) {
            return nums[n];
        }
        for (int i = nums.size(); i <= n; i++) {
            int num = 0;
            for (int j = 0; j < i; j++) {
                num += nums[j] * nums[i - 1 - j];
            }
            nums.push_back(num);
        }

        return nums[n];
    }
};

thread_local std::vector<int> Solution::nums = {1, 1};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.numTrees(0), 0);
    EXPECT_EQ(solution.numTrees(1), 1);
    EXPECT_EQ(solution.numTrees(3), 5);
}