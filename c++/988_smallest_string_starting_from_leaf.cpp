#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
   public:
    std::string smallestFromLeaf(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        if (root->left == nullptr && root->right == nullptr) {
            std::string result;
            result.push_back(root->val + 'a');
            return result;
        }
        if (root->left == nullptr) {
            auto r = smallestFromLeaf(root->right);
            r.push_back(root->val + 'a');
            return r;
        }
        if (root->right == nullptr) {
            auto l = smallestFromLeaf(root->left);
            l.push_back(root->val + 'a');
            return l;
        }
        auto l = smallestFromLeaf(root->left);
        auto r = smallestFromLeaf(root->right);
        l.push_back(root->val + 'a');
        r.push_back(root->val + 'a');
        if (l <= r) {
            return l;
        }
        return r;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({2, 2, 1, $, 1, 0, $, 0})),
              "abc");
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({0, 1, 2, 3, 4, 3, 4})),
              "dba");
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({25, 1, 3, 1, 3, 0, 2})),
              "adz");
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({19, 10})),
              "kt");
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({})),
              "");
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({0})),
              "a");
    EXPECT_EQ(solution.smallestFromLeaf(NewTree({0, 2})),
              "ca");
}