#include <gtest/gtest.h>
#include <iostream>
#include <vector>

auto vi = std::vector<int>({
    1,
    10,
    91,
    739,
    5275,
    32491,
    168571,
    712891,
    2345851,
    5611771,
    8877691,
});
 
class Solution {
   public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > vi.size()) {
            return vi.back();
        }
        return vi[n];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.countNumbersWithUniqueDigits(2), 91);
}