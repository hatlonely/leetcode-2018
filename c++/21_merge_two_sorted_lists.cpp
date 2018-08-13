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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prev(0);
        auto     node = &prev;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1         = l1->next;
            } else {
                node->next = l2;
                l2         = l2->next;
            }
            node = node->next;
        }

        if (l1 != nullptr) {
            node->next = l1;
        }

        if (l2 != nullptr) {
            node->next = l2;
        }

        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMergeTwoSortedLists, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.mergeTwoLists(NewList({1, 2, 4}), NewList({1, 3, 4})), NewList({1, 1, 2, 3, 4, 4})));
}