#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::unordered_set<int> ns1(nums1.begin(), nums1.end());
        std::unordered_set<int> ns2(nums2.begin(), nums2.end());
        std::vector<int>        vi;
        for (auto n : ns1) {
            if (ns2.count(n)) {
                vi.push_back(n);
            }
        }
        return vi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.intersection({1, 2, 2, 1}, {2, 2}), std::vector<int>({2}));
}