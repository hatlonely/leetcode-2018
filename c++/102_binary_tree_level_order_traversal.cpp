#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>
#include "treenode.hpp"

class Solution {
   public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> vvi;
        std::queue<TreeNode*>         tq;
        if (root != nullptr) {
            tq.push(root);
        }
        while (!tq.empty()) {
            auto             size = tq.size();
            std::vector<int> vi;
            vi.reserve(size);
            for (int i = 0; i < size; i++) {
                auto node = tq.front();
                tq.pop();
                vi.emplace_back(node->val);
                if (node->left != nullptr) {
                    tq.push(node->left);
                }
                if (node->right != nullptr) {
                    tq.push(node->right);
                }
            }
            vvi.emplace_back(std::move(vi));
        }
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
        solution.levelOrder(NewTree({3, 9, 20, $, $, 15, 7})),
        std::vector<std::vector<int>>({
            {3},
            {9, 20},
            {15, 7},
        }));
}
