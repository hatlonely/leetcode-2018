#include <gtest/gtest.h>
#include <iostream>
#include "listnode.hpp"

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode prev(0);
        prev.next = head;
        auto node = &prev;
        for (int i = 0; i < m - 1; i++) {
            node = node->next;
        }
        auto node1 = node->next;
        auto node2 = node1->next;
        for (int j = 0; j < n - m; j++) {
            auto node3  = node2->next;
            node2->next = node1;
            node1       = node2;
            node2       = node3;
        }

        node->next->next = node2;
        node->next       = node1;
        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.reverseBetween(NewList({1, 2, 3, 4, 5}), 2, 4), NewList({1, 4, 3, 2, 5})));
    EXPECT_TRUE(ListEqual(solution.reverseBetween(NewList({1, 2, 3, 4, 5}), 2, 5), NewList({1, 5, 4, 3, 2})));
}