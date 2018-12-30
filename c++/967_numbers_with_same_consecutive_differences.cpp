#include <gtest/gtest.h>
#include <iostream>

class Solution {
    void numsSameConsecDiffRecursive(
        int n, int k, int num,
        std::vector<int>& result) {
        if (n == 0) {
            result.push_back(num);
            return;
        }
        auto y = num % 10;
        if (y - k >= 0) {
            numsSameConsecDiffRecursive(n - 1, k, num * 10 + y - k, result);
        }
        if (k != 0 && y + k <= 9) {
            numsSameConsecDiffRecursive(n - 1, k, num * 10 + y + k, result);
        }
    }

   public:
    std::vector<int> numsSameConsecDiff(int n, int k) {
        std::vector<int> result;
        for (int i = 1; i < 10; i++) {
            numsSameConsecDiffRecursive(n - 1, k, i, result);
        }
        if (n == 1) {
            result.push_back(0);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.numsSameConsecDiff(3, 7),
        std::vector<int>({
            181,
            292,
            707,
            818,
            929,
        }));
    EXPECT_EQ(
        solution.numsSameConsecDiff(2, 1),
        std::vector<int>({
            10,
            12,
            21,
            23,
            32,
            34,
            43,
            45,
            54,
            56,
            65,
            67,
            76,
            78,
            87,
            89,
            98,
        }));
    EXPECT_EQ(
        solution.numsSameConsecDiff(1, 0),
        std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}));
    EXPECT_EQ(
        solution.numsSameConsecDiff(2, 0),
        std::vector<int>({11, 22, 33, 44, 55, 66, 77, 88, 99}));
}