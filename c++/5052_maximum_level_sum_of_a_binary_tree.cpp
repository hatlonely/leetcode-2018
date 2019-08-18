#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include "treenode.hpp"

class Solution {
   public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> sq;
        if (root != nullptr) {
            sq.push(root);
            sq.push(nullptr);
        }
        auto max   = std::numeric_limits<int>::min();
        auto ret   = 0;
        auto level = 0;
        auto sum   = 0;
        while (!sq.empty()) {
            auto node = sq.front();
            sq.pop();
            if (node == nullptr) {
                if (sum > max) {
                    max = sum;
                    ret = level;
                }
                sum = 0;
                level++;
                if (!sq.empty()) {
                    sq.push(nullptr);
                }
                continue;
            }
            sum += node->val;
            if (node->left != nullptr) {
                sq.push(node->left);
            }
            if (node->right != nullptr) {
                sq.push(node->right);
            }
        }
        return ret + 1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case5052) {
    Solution solution;
    EXPECT_EQ(solution.maxLevelSum(NewTree({1, 7, 0, 7, -8, 9, 2, 3})), 3);
    EXPECT_EQ(solution.maxLevelSum(NewTree({1, 7, 0, 7, -8})), 2);
}
