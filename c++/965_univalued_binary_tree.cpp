#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left != nullptr && root->left->val != root->val) {
            return false;
        }
        if (root->right != nullptr && root->right->val != root->val) {
            return false;
        }

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isUnivalTree(NewTree({1, 1, 1, $, 1})));
    EXPECT_FALSE(solution.isUnivalTree(NewTree({1, 1, 1, $, 2})));
    EXPECT_TRUE(solution.isUnivalTree(NewTree({1})));
}