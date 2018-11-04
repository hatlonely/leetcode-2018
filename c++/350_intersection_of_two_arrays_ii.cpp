#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::unordered_map<int, int> nt1;
        for (auto n : nums1) {
            if (!nt1.count(n)) {
                nt1[n] = 1;
            } else {
                nt1[n]++;
            }
        }
        std::vector<int> vi;
        for (auto n : nums2) {
            if (nt1.count(n) && nt1[n] > 0) {
                vi.push_back(n);
                nt1[n]--;
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
    EXPECT_EQ(solution.intersect({1, 2, 2, 1}, {2, 2}), std::vector<int>({2, 2}));
}