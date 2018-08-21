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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* node = head;
        int       n    = 1;
        while (node->next != nullptr) {
            node = node->next;
            n++;
        }
        node->next = head;
        k          = (n - k % n) % n;
        for (int i = 0; i < k; i++) {
            node = node->next;
        }
        head       = node->next;
        node->next = nullptr;
        return head;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testRotateList, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.rotateRight(NewList({1, 2, 3, 4, 5}), 0), NewList({1, 2, 3, 4, 5})));
    EXPECT_TRUE(ListEqual(solution.rotateRight(NewList({1, 2, 3, 4, 5}), 1), NewList({5, 1, 2, 3, 4})));
    EXPECT_TRUE(ListEqual(solution.rotateRight(NewList({1, 2, 3, 4, 5}), 2), NewList({4, 5, 1, 2, 3})));
    EXPECT_TRUE(ListEqual(solution.rotateRight(NewList({1, 2, 3, 4, 5}), 7), NewList({4, 5, 1, 2, 3})));
}