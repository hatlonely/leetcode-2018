#include <gtest/gtest.h>
#include <regex>
#include <string>

class Solution {
   public:
    bool isMatch(const std::string& source, const std::string& pattern) {
        return std::regex_match(source, std::regex(pattern));
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testRegularExpressionMatching, case1) {
    Solution solution;
    EXPECT_FALSE(solution.isMatch("aa", "a"));
    EXPECT_FALSE(solution.isMatch("mississippi", "mis*is*p*."));
    EXPECT_TRUE(solution.isMatch("aa", "a*"));
    EXPECT_TRUE(solution.isMatch("ab", ".*"));
    EXPECT_TRUE(solution.isMatch("aab", "c*a*b"));
}
