#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    int strStr(std::string source, std::string substr) {
        return source.find(substr);
    }
};

class SolutionSunday {
   public:
    // THIS IS A SIMPLE EXAMPLE
    // EXAMPLE
    // THIS IS A SIMPLE EXAMPLE
    //         EXAMPLE
    // THIS IS A SIMPLE EXAMPLE
    //          EXAMPLE
    // THIS IS A SIMPLE EXAMPLE
    //                  EXAMPLE
    int strStr(std::string source, std::string substr) {
        size_t idx  = 0;
        size_t len1 = source.length();
        size_t len2 = substr.length();

        while (true) {
            int i = 0;
            while (i < len2 && idx + i < len1 && source[idx + i] == substr[i]) {
                i++;
            }
            if (i == len2) {
                return idx;
            }
            idx += len2;
            if (idx >= len1) {
                return -1;
            }

            i = len2 - 1;
            while (i >= 0 && source[idx] != substr[i]) {
                i--;
            }
            idx -= i;
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testImplementStrStr, case1) {
    SolutionSunday solution;
    EXPECT_EQ(solution.strStr("hello", "ll"), 2);
    EXPECT_EQ(solution.strStr("aaaaa", "bba"), -1);
    EXPECT_EQ(solution.strStr("THIS IS A SIMPLE EXAMPLE", "EXAMPLE"), 17);
}
