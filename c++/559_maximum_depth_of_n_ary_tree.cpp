#include <gtest/gtest.h>
#include <iostream>
#include "n_ary_tree_node.hpp"

class Solution {
   public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        for (auto child : root->children) {
            depth = std::max(depth, maxDepth(child));
        }
        return depth + 1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}