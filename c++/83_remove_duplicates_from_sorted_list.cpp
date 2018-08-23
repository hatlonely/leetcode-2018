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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode prev(0);
        auto     node = &prev;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
            } else {
                node->next = head;
                node       = node->next;
                head       = head->next;
            }
        }
        node->next = nullptr;
        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.deleteDuplicates(NewList({1, 2, 3, 3, 4, 4, 5})),
                          NewList({1, 2, 3, 4, 5})));
}