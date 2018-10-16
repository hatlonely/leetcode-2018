#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    void inorderTraversalRecursive(std::vector<int>& vi, TreeNode* root) {
        if (root->left != nullptr) {
            inorderTraversalRecursive(vi, root->left);
        }
        vi.emplace_back(root->val);
        if (root->right != nullptr) {
            inorderTraversalRecursive(vi, root->right);
        }
    }

   public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vi;
        if (root != nullptr) {
            inorderTraversalRecursive(vi, root);
        }
        return vi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.inorderTraversal(NewTree({1, $, 2, 3})), std::vector<int>({1, 3, 2}));
}
