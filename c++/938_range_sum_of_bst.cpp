#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) {
            return 0;
        }
        int lv = rangeSumBST(root->left, L, R);
        int rv = rangeSumBST(root->right, L, R);
        int v  = lv + rv;
        if (L <= root->val && R >= root->val) {
            v += root->val;
        }
        return v;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
