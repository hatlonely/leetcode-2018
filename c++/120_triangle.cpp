#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] += std::min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        return *std::min_element(triangle.back().begin(), triangle.back().end());
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     triangle = std::vector<std::vector<int>>({
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    });
    EXPECT_EQ(solution.minimumTotal(triangle), 11);
}