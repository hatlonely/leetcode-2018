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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prev(0);
        auto     node = &prev;

        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            auto val   = l1->val + l2->val + carry;
            node->next = new ListNode(val % 10);
            carry      = val / 10;
            node       = node->next;
            l1         = l1->next;
            l2         = l2->next;
        }

        while (l1 != nullptr) {
            auto val   = l1->val + carry;
            node->next = new ListNode(val % 10);
            carry      = val / 10;
            node       = node->next;
            l1         = l1->next;
        }

        while (l2 != nullptr) {
            auto val   = l2->val + carry;
            node->next = new ListNode(val % 10);
            carry      = val / 10;
            node       = node->next;
            l2         = l2->next;
        }

        if (carry != 0) {
            node->next = new ListNode(carry);
        }

        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testAddTwoNumbers, case1) {
    auto     l1 = NewList({2, 4, 3});
    auto     l2 = NewList({5, 6, 4});
    Solution solution;
    auto     l3 = solution.addTwoNumbers(l1, l2);
    EXPECT_TRUE(ListEqual(l3, NewList({7, 0, 8})));
}

TEST(testAddTwoNumbers, case2) {
    auto     l1 = NewList({5});
    auto     l2 = NewList({5});
    Solution solution;
    auto     l3 = solution.addTwoNumbers(l1, l2);
    EXPECT_TRUE(ListEqual(l3, NewList({0, 1})));
}