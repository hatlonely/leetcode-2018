#include <gtest/gtest.h>
#include <bitset>
#include <iostream>
#include <string>

class Solution {
   public:
    int numJewelsInStones(std::string J, std::string S) {
        std::bitset<256> bs;
        for (auto c : J) {
            bs.set(c);
        }
        auto count = 0;
        for (auto c : S) {
            if (bs.test(c)) {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.numJewelsInStones("aA", "aAAbbbb"), 3);
}