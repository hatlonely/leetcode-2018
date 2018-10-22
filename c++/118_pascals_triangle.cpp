#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> generate(int n) {
        std::vector<std::vector<int>> vvi;
        for (int i = 0; i < n; i++) {
            vvi.emplace_back(i + 1, 0);
            vvi[i][0] = 1;
            for (int j = 1; j < i; j++) {
                vvi[i][j] = vvi[i - 1][j] + vvi[i - 1][j - 1];
            }
            vvi[i][i] = 1;
        }

        return vvi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.generate(5),
              std::vector<std::vector<int>>({
                  {1},
                  {1, 1},
                  {1, 2, 1},
                  {1, 3, 3, 1},
                  {1, 4, 6, 4, 1},
              }));
}