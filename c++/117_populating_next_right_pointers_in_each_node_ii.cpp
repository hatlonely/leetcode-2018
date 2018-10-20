#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include "treelinknode.hpp"

class Solution {
   public:
    void connect(TreeLinkNode* root) {
        std::queue<TreeLinkNode*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            int           size = st.size();
            TreeLinkNode* curr = nullptr;
            for (int i = 0; i < size; i++) {
                auto node = st.front();
                st.pop();
                if (node->left != nullptr) {
                    st.push(node->left);
                }
                if (node->right != nullptr) {
                    st.push(node->right);
                }
                if (i != 0) {
                    curr->next = node;
                }
                curr = node;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     root = NewTreeLink({1, 2, 3, 4, 5, 6, 7});
    solution.connect(root);
}
