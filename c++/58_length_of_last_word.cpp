#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    int lengthOfLastWord(const std::string& sentence) {
        int r = sentence.length() - 1;
        while (r > 0 && sentence[r] == ' ') {
            r--;
        }
        int l = r;
        while (l >= 0 && sentence[l] != ' ') {
            l--;
        }
        return r - l;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.lengthOfLastWord("hello world"), 5);
    EXPECT_EQ(solution.lengthOfLastWord("hello world "), 5);
    EXPECT_EQ(solution.lengthOfLastWord("world "), 5);
    EXPECT_EQ(solution.lengthOfLastWord(""), 0);
}