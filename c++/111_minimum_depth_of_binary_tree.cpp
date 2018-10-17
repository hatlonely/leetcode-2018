#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        auto ld = minDepth(root->left);
        auto rd = minDepth(root->right);

        if (ld == 0) {
            return rd + 1;
        }

        if (rd == 0) {
            return ld + 1;
        }

        return std::min(ld, rd) + 1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.minDepth(NewTree({3, 9, 20, $, $, 15, 7})), 2);
    EXPECT_EQ(solution.minDepth(NewTree({1, 2})), 2);
}
