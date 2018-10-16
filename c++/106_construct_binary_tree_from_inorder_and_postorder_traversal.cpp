#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    TreeNode* buildTreeRecursive(
        const std::vector<int>& inorder, int m,
        const std::vector<int>& postorder, int n, int l) {
        if (l == 0) {
            return nullptr;
        }
        auto node = new TreeNode(postorder[n + l - 1]);
        if (l > 1) {
            int i = 0;
            for (; i < l; i++) {
                if (inorder[m + i] == postorder[n + l - 1]) {
                    break;
                }
            }
            node->left  = buildTreeRecursive(inorder, m, postorder, n, i);
            node->right = buildTreeRecursive(inorder, m + i + 1, postorder, n + i, l - i - 1);
        }
        return node;
    }

   public:
    TreeNode* buildTree(const std::vector<int>& inorder, const std::vector<int>& postorder) {
        return buildTreeRecursive(inorder, 0, postorder, 0, inorder.size());
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(TreeEqual(
        solution.buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}),
        NewTree({3, 9, 20, $, $, 15, 7})));
    EXPECT_TRUE(TreeEqual(
        solution.buildTree({}, {}),
        NewTree({})));
}
