#include <gtest/gtest.h>
#include <iostream>

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* NewList(std::initializer_list<int> li) {
    ListNode prev(0);
    auto     node = &prev;
    for (const auto& i : li) {
        node->next = new ListNode(i);
        node       = node->next;
    }
    return prev.next;
}

bool ListEqual(ListNode* node1, ListNode* node2) {
    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val != node2->val) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }

    return (node1 == nullptr && node2 == nullptr);
};

void ListShow(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << "-> ";
        node = node->next;
    }
    std::cout << std::endl;
};

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