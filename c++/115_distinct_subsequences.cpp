#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int numDistinct(const std::string& s, const std::string& t) {
        int m = s.length();
        int n = t.length();
        if (m < n) {
            return 0;
        }
        if (m == n) {
            return s == t;
        }
        auto vvi = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        vvi[0][0] = (s[0] == t[0]);
        for (int i = 1; i < m; i++) {
            vvi[i][0] = vvi[i - 1][0] + (s[i] == t[0]);
            for (int j = 1; j < n; j++) {
                vvi[i][j] = (s[i] == t[j]) * vvi[i - 1][j - 1] + vvi[i - 1][j];
            }
        }

        return vvi[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.numDistinct("rabbbit", "rabbit"), 3);
    EXPECT_EQ(solution.numDistinct("babgbag", "bag"), 5);
}