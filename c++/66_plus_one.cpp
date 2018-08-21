#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int c = 0;
        digits.back()++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
            if (c == 0) {
                break;
            }
        }
        if (c != 0) {
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     digits = std::vector<int>({1, 2, 3});
    EXPECT_EQ(solution.plusOne(digits), std::vector<int>({1, 2, 4}));
}