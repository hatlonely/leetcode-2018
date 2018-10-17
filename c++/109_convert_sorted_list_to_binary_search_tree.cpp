#include <gtest/gtest.h>
#include <iostream>
#include "listnode.hpp"
#include "treenode.hpp"

class Solution {
    TreeNode* sortedListToBSTRecursive(int m, int n, ListNode*& curr) {
        if (m > n) {
            return nullptr;
        }
        auto k      = (m + n) / 2;
        auto root   = new TreeNode(0);
        root->left  = sortedListToBSTRecursive(m, k - 1, curr);
        root->val   = curr->val;
        curr        = curr->next;
        root->right = sortedListToBSTRecursive(k + 1, n, curr);
        return root;
    }

   public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto curr = head;
        auto len  = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        return sortedListToBSTRecursive(0, len - 1, curr);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(TreeEqual(
        solution.sortedListToBST(NewList({-10, -3, 0, 5, 9})),
        NewTree({0, -10, 5, $, -3, $, 9})));
}