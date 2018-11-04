#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include "treenode.hpp"

class BSTIterator {
    std::stack<TreeNode*> st;

   public:
    BSTIterator(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        auto node = st.top();
        auto val  = node->val;
        st.pop();
        node = node->right;
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
        return val;
    }
};

void travel(TreeNode* node) {
    if (node->left != nullptr) {
        travel(node->left);
    }
    std::cout << node->val << ", ";
    if (node->right != nullptr) {
        travel(node->right);
    }
}

void travel2(TreeNode* root) {
    std::stack<TreeNode*> st;
    auto                  node = root;
    while (node != nullptr) {
        st.push(node);
        node = node->left;
    }
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        std::cout << node->val << ", ";
        node = node->right;
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    BSTIterator it(NewTree({3, 2, 5, 1, $, 4}));
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(it.next(), 1);
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(it.next(), 2);
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(it.next(), 3);
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(it.next(), 4);
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(it.next(), 5);
    EXPECT_FALSE(it.hasNext());
}