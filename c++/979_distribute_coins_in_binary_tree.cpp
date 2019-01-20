#include <gtest/gtest.h>
#include <iostream>
#include "treenode.hpp"

class Solution {
    int distributeCoinsRecursive(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int  lnum = distributeCoinsRecursive(root->left, result);
        int  rnum = distributeCoinsRecursive(root->right, result);
        auto num  = lnum + rnum + root->val - 1;
        result += abs(num);
        std::cout << root->val << " " << num << std::endl;
        return num;
    }

   public:
    int distributeCoins(TreeNode* root) {
        int result = 0;
        distributeCoinsRecursive(root, result);
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.distributeCoins(NewTree({1, 0, 0, $, 3})), 4);
    EXPECT_EQ(solution.distributeCoins(NewTree({0, 3, 0})), 3);
    EXPECT_EQ(solution.distributeCoins(NewTree({1, 0, 2})), 2);
}