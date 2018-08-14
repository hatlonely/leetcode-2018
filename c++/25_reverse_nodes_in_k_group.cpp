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
        std::cout << node->val << "-> ";
        node = node->next;
    }
    std::cout << std::endl;
};

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode prev(0);
        prev.next = head;
        auto last = &prev;
        while (head != nullptr) {
            auto tail = head;
            for (int i = 1; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    last->next = head;
                    return prev.next;
                }
            }
            last->next = tail;
            tail       = tail->next;
            auto node  = head->next;
            last       = head;
            head->next = nullptr;
            while (node != tail) {
                auto temp  = node->next;
                node->next = head;
                head       = node;
                node       = temp;
            }

            head = tail;
        }

        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testReverseNodesInKGroup, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.reverseKGroup(NewList({1, 2, 3, 4}), 2), NewList({2, 1, 4, 3})));
    EXPECT_TRUE(ListEqual(solution.reverseKGroup(NewList({1, 2, 3, 4}), 3), NewList({3, 2, 1, 4})));
    EXPECT_TRUE(ListEqual(solution.reverseKGroup(NewList({1, 2, 3}), 2), NewList({2, 1, 3})));
    EXPECT_TRUE(ListEqual(solution.reverseKGroup(NewList({1, 2, 3}), 1), NewList({1, 2, 3})));
}
