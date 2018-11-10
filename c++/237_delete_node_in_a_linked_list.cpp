#include <gtest/gtest.h>
#include <iostream>
#include "listnode.hpp"

class Solution {
   public:
    void deleteNode(ListNode* node) {
        node->val  = node->next->val;
        node->next = node->next->next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
