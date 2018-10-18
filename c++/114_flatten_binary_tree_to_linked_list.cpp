#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    TreeNode* flattenRecursive(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        if (root->left != nullptr && root->right != nullptr) {
            auto l      = flattenRecursive(root->left);
            auto r      = flattenRecursive(root->right);
            l->right    = root->right;
            root->right = root->left;
            root->left  = nullptr;
            return r;
        }
        if (root->right == nullptr) {
            root->right = root->left;
            root->left  = nullptr;
        }
        return flattenRecursive(root->right);
    }

   public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flattenRecursive(root);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     root = NewTree({1, 2, 5, 3, 4, $, 6});
    solution.flatten(root);
    EXPECT_TRUE(TreeEqual(root, NewTree({1, $, 2, $, 3, $, 4, $, 5, $, 6})));
}
