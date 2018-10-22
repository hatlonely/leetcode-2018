#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
   public:
    int maxProfit(const std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int              n = prices.size();
        std::vector<int> profits(n, 0);

        int maxProfit1 = 0;
        int minPrice   = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            minPrice   = std::min(minPrice, prices[i]);
            maxProfit1 = std::max(maxProfit1, prices[i] - minPrice);
            profits[i] += maxProfit1;
        }

        int maxProfit2 = 0;
        int maxPrice   = 0;
        for (int i = n - 1; i > 0; i--) {
            maxPrice   = std::max(maxPrice, prices[i]);
            maxProfit2 = std::max(maxProfit2, maxPrice - prices[i]);
            profits[i - 1] += maxProfit2;
        }

        return *std::max_element(profits.begin(), profits.end());
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.maxProfit({3, 3, 5, 0, 0, 3, 1, 4}), 6);
    EXPECT_EQ(solution.maxProfit({1, 2, 3, 4, 5}), 4);
    EXPECT_EQ(solution.maxProfit({1}), 0);
    EXPECT_EQ(solution.maxProfit({}), 0);
}