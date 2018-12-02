#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        auto nums = std::vector<int>(deck.size(), 0);
        std::sort(deck.begin(), deck.end());

        int j   = 0;
        int n   = deck.size();
        nums[0] = deck[0];
        for (int i = 1; i < n; i++) {
            do {
                j++;
                j %= n;
            } while (nums[j] != 0);
            do {
                j++;
                j %= n;
            } while (nums[j] != 0);
            nums[j] = deck[i];
        }

        return nums;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     deck = std::vector<int>({
        17,
        13,
        11,
        2,
        3,
        5,
        7,
    });
    EXPECT_EQ(
        solution.deckRevealedIncreasing(deck),
        std::vector<int>({
            2,
            13,
            3,
            11,
            5,
            17,
            7,
        }));
}