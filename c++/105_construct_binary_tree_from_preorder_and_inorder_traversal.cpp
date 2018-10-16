#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    TreeNode* buildTreeRecursive(
        const std::vector<int>& preorder, int m,
        const std::vector<int>& inorder, int n, int l) {
        if (l == 0) {
            return nullptr;
        }
        auto node = new TreeNode(preorder[m]);
        if (l > 1) {
            int i = 0;
            for (; i < l; i++) {
                if (inorder[n + i] == preorder[m]) {
                    break;
                }
            }
            node->left  = buildTreeRecursive(preorder, m + 1, inorder, n, i);
            node->right = buildTreeRecursive(preorder, m + 1 + i, inorder, n + i + 1, l - i - 1);
        }
        return node;
    }

   public:
    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        return buildTreeRecursive(preorder, 0, inorder, 0, preorder.size());
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(TreeEqual(
        solution.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}),
        NewTree({3, 9, 20, $, $, 15, 7})));
    EXPECT_TRUE(TreeEqual(
        solution.buildTree({}, {}),
        NewTree({})));
}
