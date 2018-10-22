#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
   public:
    int maxProfit(const std::vector<int>& prices) {
        int minPrice  = std::numeric_limits<int>::max();
        int maxProfit = 0;
        for (auto price : prices) {
            minPrice  = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.maxProfit({7, 1, 5, 3, 6, 4}), 5);
}