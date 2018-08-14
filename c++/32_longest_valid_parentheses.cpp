#include <gtest/gtest.h>
#include <stack>
#include <string>

class Solution {
   public:
    int longestValidParentheses(const std::string& str) {
        int             longest = 0;
        int             start   = -1;
        std::stack<int> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    start = i;
                    continue;
                }
                st.pop();
                if (st.empty()) {
                    longest = std::max(longest, i - start);
                } else {
                    longest = std::max(longest, i - st.top());
                }
            }
        }
        return longest;
    }
};

class Solution1 {
   public:
    int longestValidParentheses(const std::string& str) {
        int longest = 0;
        for (int i = 0; i < str.length(); i++) {
            int val = 0;
            for (int j = i; j < str.length(); j++) {
                if (str[j] == '(') {
                    val++;
                } else {
                    val--;
                }
                if (val < 0) {
                    break;
                }
                if (val == 0) {
                    longest = std::max(longest, j - i + 1);
                }
            }
        }
        return longest;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testLongestValidParentheses, case1) {
    Solution solution;
    EXPECT_EQ(solution.longestValidParentheses("(()"), 2);
    EXPECT_EQ(solution.longestValidParentheses(")(()))"), 4);
    EXPECT_EQ(solution.longestValidParentheses(")()())"), 4);
    EXPECT_EQ(solution.longestValidParentheses("(()()"), 4);
    EXPECT_EQ(solution.longestValidParentheses("()"), 2);
}
