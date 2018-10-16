#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include "treenode.hpp"

class Solution {
    bool isValidBSTRecursive(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        if (!isValidBSTRecursive(root->left, min, root->val)) {
            return false;
        }
        if (!isValidBSTRecursive(root->right, root->val, max)) {
            return false;
        }
        return true;
    }

   public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecursive(root, long(std::numeric_limits<int>::min()) - 1, long(std::numeric_limits<int>::max()) + 1);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_FALSE(solution.isValidBST(NewTree({5, 1, 4, $, $, 3, 6})));
    EXPECT_TRUE(solution.isValidBST(NewTree({2, 1, 3})));
    EXPECT_TRUE(solution.isValidBST(NewTree({0, $, 1})));
    EXPECT_FALSE(solution.isValidBST(NewTree({1, 1})));
    EXPECT_FALSE(solution.isValidBST(NewTree({5, 14, $, 1})));
}