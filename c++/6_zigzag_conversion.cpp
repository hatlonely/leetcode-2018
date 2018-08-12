#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    std::string convert(const std::string& str, int n) {
        if (n == 1) {
            return str;
        }
        std::string strcopy(str);
        size_t      idx = 0;
        for (size_t j = 0; j * (2 * n - 2) < str.length(); j++) {
            strcopy[idx++] = str[j * (2 * n - 2)];
        }
        for (size_t i = 1; i < n - 1; i++) {
            for (size_t j = 0;; j++) {
                size_t idx1 = j * (2 * n - 2) + i;
                size_t idx2 = (j + 1) * (2 * n - 2) - i;
                if (idx1 < str.length()) {
                    strcopy[idx++] = str[idx1];
                }
                if (idx2 < str.length()) {
                    strcopy[idx++] = str[idx2];
                } else {
                    break;
                }
            }
        }
        for (size_t j = 0; j * (2 * n - 2) + n - 1 < str.length(); j++) {
            strcopy[idx++] = str[j * (2 * n - 2) + n - 1];
        }
        return strcopy;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testZigzagConversion, case1) {
    Solution solution;
    EXPECT_EQ(solution.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(solution.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    EXPECT_EQ(solution.convert("0123456789", 3), "0481357926");
    EXPECT_EQ(solution.convert("0", 1), "0");
    EXPECT_EQ(solution.convert("0", 2), "0");
    EXPECT_EQ(solution.convert("AB", 1), "AB");
    EXPECT_EQ(solution.convert("012", 2), "021");
}
