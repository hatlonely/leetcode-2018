#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
   public:
    bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3) {
        int m = s1.length();
        int n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        auto vvb  = std::vector<std::vector<bool>>(m + 1, std::vector<bool>(n + 1, false));
        vvb[0][0] = true;
        for (int j = 1; j < n + 1; j++) {
            vvb[0][j] = (s2[j - 1] == s3[j - 1] && vvb[0][j - 1]);
        }
        for (int i = 1; i < m + 1; i++) {
            vvb[i][0] = (s1[i - 1] == s3[i - 1] && vvb[i - 1][0]);
            for (int j = 1; j < n + 1; j++) {
                vvb[i][j] = (s1[i - 1] == s3[i + j - 1] && vvb[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && vvb[i][j - 1]);
            }
        }

        return vvb[m][n];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    EXPECT_TRUE(solution.isInterleave("", "b", "b"));
    EXPECT_FALSE(solution.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    EXPECT_FALSE(solution.isInterleave("db", "b", "cbb"));
}