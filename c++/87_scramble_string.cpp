#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    bool isScramble(std::string str1, std::string str2) {
        if (str1.length() != str2.length()) {
            return false;
        }

        if (str1 == str2) {
            return true;
        }

        std::string str1_copy(str1);
        std::string str2_copy(str2);
        std::sort(str1_copy.begin(), str1_copy.end());
        std::sort(str2_copy.begin(), str2_copy.end());
        if (str1_copy != str2_copy) {
            return false;
        }

        int len = (int)str1.length();

        for (int i = 1; i < len; i++) {
            if (isScramble(str1.substr(0, i), str2.substr(0, i)) &&
                isScramble(str1.substr(i), str2.substr(i))) {
                return true;
            }

            if (isScramble(str1.substr(0, i), str2.substr(len - i)) &&
                isScramble(str1.substr(i), str2.substr(0, len - i))) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isScramble("great", "rgtae"));
    EXPECT_TRUE(solution.isScramble("abc", "bca"));
    EXPECT_TRUE(solution.isScramble("abcd", "cabd"));
    EXPECT_FALSE(solution.isScramble("abcde", "caebd"));
}