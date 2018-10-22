#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(const std::vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    EXPECT_EQ(solution.maxProfit({7, 1, 5, 3, 6, 4}), 7);
}