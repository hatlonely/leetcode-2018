#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2 == nullptr;
        }
        if (root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     root1 = NewTree({1, 2, 3, 4, 5, 6, $, $, $, 7, 8});
    auto     root2 = NewTree({1, 3, 2, $, 6, 4, 5, $, $, $, $, 8, 7});
    EXPECT_TRUE(solution.flipEquiv(root1, root2));
}
