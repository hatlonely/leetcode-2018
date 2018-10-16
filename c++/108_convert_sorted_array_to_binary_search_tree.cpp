#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    TreeNode* sortedArrayToBSTRecursive(const std::vector<int>& nums, int m, int n) {
        if (m > n) {
            return nullptr;
        }
        int  k      = (m + n) / 2;
        auto node   = new TreeNode(nums[k]);
        node->left  = sortedArrayToBSTRecursive(nums, m, k - 1);
        node->right = sortedArrayToBSTRecursive(nums, k + 1, n);
        return node;
    }

   public:
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        return sortedArrayToBSTRecursive(nums, 0, int(nums.size()) - 1);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(TreeEqual(solution.sortedArrayToBST({-10, -3, 0, 5, 9}), NewTree({0, -10, 5, $, -3, $, 9})));
}
