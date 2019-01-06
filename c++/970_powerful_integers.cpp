#include <gtest/gtest.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<int> powerfulIntegers(int x, int y, int bound) {
        std::unordered_set<int> numset;
        int                     i = 0;
        while (std::pow(x, i) <= bound) {
            int j = 0;
            while (std::pow(x, i) + std::pow(y, j) <= bound) {
                int num = std::pow(x, i) + std::pow(y, j);
                numset.insert(num);
                j++;
                if (y == 1) {
                    break;
                }
            }
            i++;
            if (x == 1) {
                break;
            }
        }
        return std::vector<int>(numset.begin(), numset.end());
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    // EXPECT_EQ(solution.powerfulIntegers(3, 5, 15), std::vector<int>({2, 4, 6, 8, 10, 14}));
}