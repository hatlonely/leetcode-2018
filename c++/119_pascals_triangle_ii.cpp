#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> getRow(int i) {
        if (i == 0) {
            return {1};
        }
        auto vi = getRow(i - 1);
        for (int j = 0; j < i - 1; j++) {
            vi[j] = vi[j] + vi[j + 1];
        }
        vi.insert(vi.begin(), 1);
        return vi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.getRow(3), std::vector<int>({1, 3, 3, 1}));
}