#include <gtest/gtest.h>
#include <set>
#include <vector>

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

struct ListNodeCompare {
    bool operator()(const ListNode* x, const ListNode* y) const {
        return x->val < y->val;
    }
};

class Solution {
   public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode prev(0);
        auto     node = &prev;
        auto     ns   = std::multiset<ListNode*, ListNodeCompare>();
        for (auto& li : lists) {
            if (li != nullptr) {
                ns.insert(li);
            }
        }

        while (!ns.empty()) {
            auto it = ns.begin();
            auto li = *it;
            ns.erase(it);
            node->next = li;
            node       = node->next;
            li         = li->next;
            if (li != nullptr) {
                ns.insert(li);
            }
        }

        return prev.next;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMergeKSortedLists, case1) {
    Solution               solution;
    std::vector<ListNode*> lists = {
        NewList({1, 4, 5}),
        NewList({1, 3, 4}),
        NewList({2, 6}),
    };
    auto result = NewList({1, 1, 2, 3, 4, 4, 5, 6});
    EXPECT_TRUE(ListEqual(solution.mergeKLists(lists), result));
}

TEST(testMergeKSortedLists, case2) {
    Solution               solution;
    std::vector<ListNode*> lists  = {{}};
    auto                   result = NewList({});
    EXPECT_TRUE(ListEqual(solution.mergeKLists(lists), nullptr));
}
