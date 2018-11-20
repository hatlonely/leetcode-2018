#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>
#include "n_ary_tree_node.hpp"

class Solution {
   public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        auto              vvs = std::vector<std::vector<int>>();
        std::queue<Node*> qn;
        if (root != nullptr) {
            qn.push(root);
        }
        while (!qn.empty()) {
            int  size = qn.size();
            auto vs   = std::vector<int>();
            for (int i = 0; i < size; i++) {
                auto node = qn.front();
                vs.push_back(node->val);
                qn.pop();
                for (auto child : node->children) {
                    qn.push(child);
                }
            }
            vvs.emplace_back(std::move(vs));
        }
        return vvs;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
