#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
   public:
    TreeNode* constructMaximumBinaryTreeRecursive(const std::vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int idx = l;
        int max = nums[l];
        for (int i = l + 1; i <= r; i++) {
            if (max < nums[i]) {
                idx = i;
                max = nums[i];
            }
        }
        auto node   = new TreeNode(max);
        node->left  = constructMaximumBinaryTreeRecursive(nums, l, idx - 1);
        node->right = constructMaximumBinaryTreeRecursive(nums, idx + 1, r);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(const std::vector<int>& nums) {
        return constructMaximumBinaryTreeRecursive(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    TreeShow(solution.constructMaximumBinaryTree({3, 2, 1, 6, 0, 5}));
}