#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include "treenode.hpp"

class Solution {
   public:
    int countNode(TreeNode* root) {
        std::stack<TreeNode*> st;
        int                   count = 0;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            auto node = st.top();
            count++;
            st.pop();
            if (node->left != nullptr) {
                st.push(node->left);
            }
            if (node->right != nullptr) {
                st.push(node->right);
            }
        }

        return count;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* lnode = nullptr;
        TreeNode* rnode = nullptr;
        {
            std::stack<TreeNode*> st;
            st.push(root);
            while (!st.empty()) {
                auto node = st.top();
                if (node->val == x) {
                    lnode = node->left;
                    rnode = node->right;
                    break;
                }
                st.pop();
                if (node->left != nullptr) {
                    st.push(node->left);
                }
                if (node->right != nullptr) {
                    st.push(node->right);
                }
            }
        }

        int lnum = countNode(lnode);
        int rnum = countNode(rnode);

        return lnum > n - lnum || rnum > n - rnum || n - lnum - rnum - 1 > lnum + rnum;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     root = NewTree({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    EXPECT_TRUE(solution.btreeGameWinningMove(root, 11, 3));
}

TEST(test, case2) {
    Solution solution;
    auto     root = NewTree({1, 2, 3, 4, 5});
    EXPECT_FALSE(solution.btreeGameWinningMove(root, 5, 2));
}
