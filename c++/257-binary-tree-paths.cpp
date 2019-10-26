#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

using namespace std;

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<string> vs;
        if (root->left != nullptr) {
            auto lvs = binaryTreePaths(root->left);
            for (auto s : lvs) {
                vs.emplace_back(to_string(root->val) + "->" + s);
            }
        }
        if (root->right != nullptr) {
            auto rvs = binaryTreePaths(root->right);
            for (auto s : rvs) {
                vs.emplace_back(to_string(root->val) + "->" + s);
            }
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {to_string(root->val)};
        }

        return vs;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     vs = solution.binaryTreePaths(NewTree({1, 2, 3, $, 5}));
    EXPECT_EQ(vs, vector<string>({"1->2->5", "1->3"}));
}