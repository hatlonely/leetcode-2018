#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
    thread_local static std::vector<std::vector<int>> codes;

   public:
    std::vector<int> grayCode(int n) {
        while (codes.size() <= n) {
            std::vector<int> code;
            auto&            back = codes.back();
            int              size = back.size();
            code.reserve(size * 2);
            for (int i = 0; i < size; i++) {
                code.push_back(back[i]);
            }
            for (int i = size - 1; i >= 0; i--) {
                code.push_back(back[i] + size);
            }
            codes.emplace_back(std::move(code));
        }

        return codes[n];
    }
};

thread_local std::vector<std::vector<int>> Solution::codes = {{0}};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.grayCode(2), std::vector<int>({0, 1, 3, 2}));
}