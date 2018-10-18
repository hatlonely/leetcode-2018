#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    void pathSumRecursive(TreeNode* root, int sum, std::vector<int>& vi, std::vector<std::vector<int>>& vvi) {
        if (root == nullptr) {
            return;
        }
        vi.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == sum) {
            vvi.push_back(vi);
        } else {
            pathSumRecursive(root->left, sum - root->val, vi, vvi);
            pathSumRecursive(root->right, sum - root->val, vi, vvi);
        }
        vi.pop_back();
    }

   public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<int>              vi;
        std::vector<std::vector<int>> vvi;
        pathSumRecursive(root, sum, vi, vvi);
        return vvi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.pathSum(NewTree({5, 4, 8, 11, $, 13, 4, 7, 2, $, $, 5, 1}), 22),
        std::vector<std::vector<int>>({
            {5, 4, 11, 2},
            {5, 8, 4, 5},
        }));
}
