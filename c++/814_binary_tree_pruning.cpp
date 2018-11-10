#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    TreeNode* pruneTree(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        node->left  = pruneTree(node->left);
        node->right = pruneTree(node->right);
        if (node->left == nullptr && node->right == nullptr && node->val == 0) {
            return nullptr;
        }
        return node;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
