#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    void recoverTreeRecursive(TreeNode*& prev, TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2) {
        if (root == nullptr) {
            return;
        }
        recoverTreeRecursive(prev, root->left, mistake1, mistake2);
        if (prev != nullptr && prev->val > root->val) {
            if (mistake1 == nullptr) {
                mistake1 = prev;
                mistake2 = root;
            } else {
                mistake2 = root;
            }
        }
        prev = root;
        recoverTreeRecursive(prev, root->right, mistake1, mistake2);
    }

   public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev     = nullptr;
        TreeNode* mistake1 = nullptr;
        TreeNode* mistake2 = nullptr;
        recoverTreeRecursive(prev, root, mistake1, mistake2);
        std::swap(mistake1->val, mistake2->val);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     root = NewTree({1, 3, $, $, 2});
    solution.recoverTree(root);
    EXPECT_TRUE(TreeEqual(root, NewTree({3, 1, $, $, 2})));
}

TEST(test, case2) {
    Solution solution;
    auto     root = NewTree({3, 1, 4, $, $, 2});
    solution.recoverTree(root);
    EXPECT_TRUE(TreeEqual(root, NewTree({2, 1, 4, $, $, 3})));
}

TEST(test, case3) {
    Solution solution;
    auto     root = NewTree({2, 1, $, $, 3});
    solution.recoverTree(root);
    EXPECT_TRUE(TreeEqual(root, NewTree({3, 1, $, $, 2})));
}