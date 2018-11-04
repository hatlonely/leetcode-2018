#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string reorganizeString(std::string str) {
        auto n = str.size();
        if (n <= 1) {
            return str;
        }
        std::sort(str.begin(), str.end());
        std::string strcopy = std::string(str.size(), '\0');
        auto        m       = (str.size() + 1) / 2;
        for (int i = 0; i < str.size(); i++) {
            if (i % 2 == 0) {
                strcopy[i] = str[i / 2];
            } else {
                strcopy[i] = str[i / 2 + m];
            }
        }

        int split = 0;
        for (int i = 1; i < strcopy.size(); i++) {
            if (strcopy[i] == strcopy[i - 1]) {
                if (split == 0) {
                    split = i;
                } else {
                    return "";
                }
            }
        }
        return strcopy.substr(split) + strcopy.substr(0, split);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.reorganizeString("aabba"), "ababa");
    EXPECT_EQ(solution.reorganizeString("baba"), "abab");
    EXPECT_EQ(solution.reorganizeString("aaab"), "");
    EXPECT_EQ(solution.reorganizeString("vvvlo"), "vlvov");
    EXPECT_EQ(solution.reorganizeString("blflxll"), "lxlblfl");
}