#include <gtest/gtest.h>

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

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* node, int n) {
        ListNode prev(0);
        prev.next  = node;
        auto node1 = &prev;
        auto node2 = node;

        for (int i = 0; i < n - 1; i++) {
            node2 = node2->next;
            if (node2 == nullptr) {
                return node;
            }
        }

        while (node2->next != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
        }

        node2       = node1->next;
        node1->next = node1->next->next;
        delete node2;

        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testRemoveNthNodeFromEndOfList, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.removeNthFromEnd(NewList({1, 2, 3, 4, 5}), 2), NewList({1, 2, 3, 5})));
}
