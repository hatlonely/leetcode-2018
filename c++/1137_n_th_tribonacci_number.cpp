#include <gtest/gtest.h>
#include <iostream>

class Solution {
    std::vector<int> vi = {0, 1, 1};

   public:
    int tribonacci(int n) {
        if (n < vi.size()) {
            return vi[n];
        }

        while (vi.size() < n + 1) {
            vi.emplace_back(*vi.rbegin() + *(vi.rbegin() + 1) + *(vi.rbegin() + 2));
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
    EXPECT_EQ(solution.tribonacci(25), 1389537);
    EXPECT_EQ(solution.tribonacci(0), 0);
    EXPECT_EQ(solution.tribonacci(1), 1);
    EXPECT_EQ(solution.tribonacci(2), 1);
}
