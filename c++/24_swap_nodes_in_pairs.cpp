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
    ListNode* swapPairs(ListNode* head) {
        ListNode prev(0);
        prev.next  = head;
        auto node0 = &prev;

        while (node0->next != nullptr && node0->next->next != nullptr) {
            auto node1  = node0->next;
            auto node2  = node1->next;
            node1->next = node2->next;
            node2->next = node1;
            node0->next = node2;
            node0       = node1;
        }

        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testSwapNodesInPairs, case1) {
    Solution solution;
    EXPECT_TRUE(ListEqual(solution.swapPairs(NewList({1, 2, 3, 4})), NewList({2, 1, 4, 3})));
    EXPECT_TRUE(ListEqual(solution.swapPairs(NewList({1, 2, 3})), NewList({2, 1, 3})));
}
