#include <gtest/gtest.h>
#include <map>
#include <stack>
#include <string>

const std::map<char, char> kParenthesesMap = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
};

class Solution {
   public:
    bool isValid(const std::string& str) {
        std::stack<char> st;
        for (const auto& ch : str) {
            if (kParenthesesMap.count(ch) > 0) {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (ch != kParenthesesMap.at(st.top())) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testValidParentheses, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isValid("()"));
    EXPECT_TRUE(solution.isValid("()[]{}"));
    EXPECT_FALSE(solution.isValid("(]"));
    EXPECT_FALSE(solution.isValid("([)]"));
    EXPECT_TRUE(solution.isValid("{[]}"));
}
