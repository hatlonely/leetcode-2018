#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "treenode.hpp"

class Solution {
    bool flipMatchVoyageRecursive(
        TreeNode*               root,
        const std::vector<int>& voyage, int s, int e,
        std::vector<int>& vi) {
        if (root->val != voyage[s]) {
            return false;
        }

        if (root->left != nullptr && root->left->val == voyage[s + 1]) {
            if (root->right == nullptr) {
                return flipMatchVoyageRecursive(root->left, voyage, s + 1, e, vi);
            }

            int i = s + 1;
            for (; i <= e; i++) {
                if (voyage[i] == root->right->val) {
                    break;
                }
            }
            if (i > e) {
                return false;
            }
            auto b1 = flipMatchVoyageRecursive(root->left, voyage, s + 1, i - 1, vi);
            auto b2 = flipMatchVoyageRecursive(root->right, voyage, i, e, vi);
            return b1 && b2;
        }
        if (root->right != nullptr && root->right->val == voyage[s + 1]) {
            if (root->left == nullptr) {
                return flipMatchVoyageRecursive(root->right, voyage, s + 1, e, vi);
            }

            int i = s + 1;
            for (; i <= e; i++) {
                if (voyage[i] == root->left->val) {
                    break;
                }
            }
            if (i > e) {
                return false;
            }
            auto b1 = flipMatchVoyageRecursive(root->right, voyage, s + 1, i - 1, vi);
            auto b2 = flipMatchVoyageRecursive(root->left, voyage, i, e, vi);

            vi.push_back(root->val);
            return b1 && b2;
        }

        return root->left == nullptr && root->right == nullptr && s == e;
    }

   public:
    std::vector<int> flipMatchVoyage(TreeNode* root, const std::vector<int>& voyage) {
        std::vector<int> vi;
        if (!flipMatchVoyageRecursive(root, voyage, 0, voyage.size() - 1, vi)) {
            return {-1};
        }
        return vi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.flipMatchVoyage(NewTree({1, 2, 3}), std::vector<int>({1, 3, 2})),
        std::vector<int>({1}));
    EXPECT_EQ(
        solution.flipMatchVoyage(NewTree({1, 2, 3}), std::vector<int>({1, 2, 3})),
        std::vector<int>({}));
    EXPECT_EQ(
        solution.flipMatchVoyage(NewTree({1, 2}), std::vector<int>({2, 1})),
        std::vector<int>({-1}));
    EXPECT_EQ(
        solution.flipMatchVoyage(NewTree({1, 2, 3}), std::vector<int>({1, 2})),
        std::vector<int>({-1}));
}