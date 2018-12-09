#include <gtest/gtest.h>
#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    bool canReorderDoubled(const std::vector<int>& nums) {
        std::multiset<int> nset(nums.begin(), nums.end());
        while (!nset.empty()) {
            auto n = *nset.begin();
            nset.erase(nset.begin());
            if (n < 0) {
                if (n % 2 != 0) {
                    return false;
                }
                auto it = nset.find(n / 2);
                if (it == nset.end()) {
                    return false;
                }
                nset.erase(it);
            } else if (n > 0) {
                auto it = nset.find(n * 2);
                if (it == nset.end()) {
                    return false;
                }
                nset.erase(it);
            } else {
                auto it = nset.find(n);
                if (it == nset.end()) {
                    return false;
                }
                nset.erase(it);
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.canReorderDoubled({4, -2, 2, -4}));
    EXPECT_FALSE(solution.canReorderDoubled({1, 2, 4, 16, 8, 4}));
}