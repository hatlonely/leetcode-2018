#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    std::string longestPalindrome(const std::string& str) {
        if (str.empty()) {
            return str;
        }

        size_t idx1 = 0;
        size_t len1 = 0;
        for (size_t i = 0; i < str.length(); i++) {
            size_t j = 1;
            while (i + j < str.length() && i >= j && str[i - j] == str[i + j]) {
                j++;
            }
            if (j > len1) {
                idx1 = i;
                len1 = j;
            }
        }

        size_t idx2 = 0;
        size_t len2 = 0;
        for (size_t i = 0; i < str.length(); i++) {
            size_t j = 0;
            while (i + j + 1 < str.length() && i >= j && str[i - j] == str[i + j + 1]) {
                j++;
            }
            if (j > len2) {
                idx2 = i;
                len2 = j;
            }
        }
        if (len1 > len2) {
            return str.substr(idx1 - len1 + 1, 2 * len1 - 1);
        }
        return str.substr(idx2 - len2 + 1, 2 * len2);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testLongestPalidrom, case1) {
    Solution solution;
    EXPECT_EQ(solution.longestPalindrome("babad"), "bab");
    EXPECT_EQ(solution.longestPalindrome("cbbd"), "bb");
}
