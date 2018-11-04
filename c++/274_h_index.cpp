#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        int i = 0;
        while (i < citations.size() && citations[i] >= i + 1) {
            i++;
        }

        return i;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     citations = std::vector<int>({3, 0, 6, 1, 5});
    EXPECT_EQ(solution.hIndex(citations), 3);
}