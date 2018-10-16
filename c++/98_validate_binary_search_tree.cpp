#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    void isValidBSTRecursive(int& min, int& max, bool& isBST, TreeNode* root) {
        min = root->val;
        max = root->val;
        if (root->left == nullptr && root->right == nullptr) {
            min   = root->val;
            max   = root->val;
            isBST = true;
            return;
        }
        int  lmin, lmax, rmin, rmax;
        bool lisBST, risBST;
        if (root->left != nullptr) {
            isValidBSTRecursive(lmin, lmax, lisBST, root->left);
            if (!lisBST || lmax >= root->val) {
                isBST = false;
                return;
            }
            min = lmin;
        }
        if (root->right != nullptr) {
            isValidBSTRecursive(rmin, rmax, risBST, root->right);
            if (!risBST || rmin <= root->val) {
                isBST = false;
                return;
            }
            max = rmax;
        }
        isBST = true;
    }

   public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int  min, max;
        bool isBST;
        isValidBSTRecursive(min, max, isBST, root);
        return isBST;
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