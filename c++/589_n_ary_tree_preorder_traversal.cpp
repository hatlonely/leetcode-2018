#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>
#include "n_ary_tree_node.hpp"

class Solution {
   public:
    std::vector<int> preorder(Node* root) {
        std::vector<int>  vs;
        std::stack<Node*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            vs.push_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                st.push(*it);
            }
        }
        return vs;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}