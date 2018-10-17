#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    bool isBalancedRecursive(TreeNode* root, int& h) {
        if (root == nullptr) {
            h = 0;
            return true;
        }
        int lh;
        int rh;
        if (!isBalancedRecursive(root->left, lh)) {
            return false;
        }
        if (!isBalancedRecursive(root->right, rh)) {
            return false;
        }
        if (lh - rh > 1 || rh - lh > 1) {
            return false;
        }

        h = std::max(lh, rh) + 1;

        return true;
    }

   public:
    bool isBalanced(TreeNode* root) {
        int h;
        return isBalancedRecursive(root, h);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isBalanced(NewTree({3, 9, 20, $, $, 15, 7})));
    EXPECT_FALSE(solution.isBalanced(NewTree({1, 2, 2, 3, 3, $, $, 4, 4})));
}