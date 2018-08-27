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

void ListShow(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
};

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lowerX(0);
        ListNode upperX(0);
        auto     lowerTail = &lowerX;
        auto     upperTail = &upperX;

        while (head != nullptr) {
            if (head->val < x) {
                lowerTail->next = head;
                lowerTail       = head;
            } else {
                upperTail->next = head;
                upperTail       = head;
            }
            head = head->next;
        }
        lowerTail->next = upperX.next;
        upperTail->next = nullptr;

        return lowerX.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.partition(NewList({1, 4, 3, 2, 5, 2}), 3),
                          NewList({1, 2, 2, 4, 3, 5})));
    EXPECT_TRUE(ListEqual(solution.partition(NewList({4, 1, 3, 2, 5, 2}), 3),
                          NewList({1, 2, 2, 4, 3, 5})));
    EXPECT_TRUE(ListEqual(solution.partition(NewList({1}), 0),
                          NewList({1})));
}