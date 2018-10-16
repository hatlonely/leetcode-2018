#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    bool isSymmetricRecursive(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr) {
            return node2 == nullptr;
        }
        if (node2 == nullptr) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        if (!isSymmetricRecursive(node1->left, node2->right)) {
            return false;
        }
        if (!isSymmetricRecursive(node1->right, node2->left)) {
            return false;
        }
        return true;
    }

   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetricRecursive(root->left, root->right);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isSymmetric(NewTree({1, 2, 2, 3, 4, 4, 3})));
}