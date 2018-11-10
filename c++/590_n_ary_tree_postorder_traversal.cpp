#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>
#include "n_ary_tree_node.hpp"

class Solution {
   public:
    void postorderRecursive(Node* root, std::vector<int>& vs) {
        for (auto& child : root->children) {
            postorderRecursive(child, vs);
        }
        vs.push_back(root->val);
    }

    std::vector<int> postorder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> vs;
        postorderRecursive(root, vs);
        return vs;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
