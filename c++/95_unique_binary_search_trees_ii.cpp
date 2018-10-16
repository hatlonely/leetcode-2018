#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    std::vector<TreeNode*> generateTreesRecursive(int m, int n) {
        if (m > n) {
            return {nullptr};
        }
        if (m == n) {
            return {new TreeNode(m)};
        }
        std::vector<TreeNode*> trees;
        for (int i = m; i <= n; i++) {
            auto ltrees = generateTreesRecursive(m, i - 1);
            auto rtrees = generateTreesRecursive(i + 1, n);
            for (auto ltree : ltrees) {
                for (auto rtree : rtrees) {
                    auto tree   = new TreeNode(i);
                    tree->left  = ltree;
                    tree->right = rtree;
                    trees.emplace_back(tree);
                }
            }
        }
        return trees;
    }

   public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTreesRecursive(1, n);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     trees = solution.generateTrees(3);
    auto     nodes = std::vector<TreeNode*>({
        NewTree({1, $, 2, $, 3}),
        NewTree({1, $, 3, 2}),
        NewTree({2, 1, 3}),
        NewTree({3, 1, $, $, 2}),
        NewTree({3, 2, $, 1}),
    });
    EXPECT_EQ(trees.size(), nodes.size());
    for (int i = 0; i < trees.size(); i++) {
        TreeShow(trees[i]);
        EXPECT_TRUE(TreeEqual(trees[i], nodes[i]));
    }
}

TEST(test, case2) {
    Solution solution;
    EXPECT_TRUE(solution.generateTrees(0).empty());
}
