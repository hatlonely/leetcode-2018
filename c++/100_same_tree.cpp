#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr) {
            return node2 == nullptr;
        }
        if (node2 == nullptr) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        if (!isSameTree(node1->left, node2->left)) {
            return false;
        }
        if (!isSameTree(node1->right, node2->right)) {
            return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isSameTree(NewTree({1, 2, 3}), NewTree({1, 2, 3})));
    EXPECT_FALSE(solution.isSameTree(NewTree({1, 2, 3}), NewTree({1, $, 2, 3})));
}