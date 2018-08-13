#include <gtest/gtest.h>
#include <string>
#include <vector>

class Solution {
   public:
    void generateParenthesisRecursive(int n, std::vector<std::string>& parenthesis, const std::string& prefix, int l, int r) {
        if (prefix.length() == n * 2) {
            parenthesis.emplace_back(prefix);
            return;
        }
        if (l < n) {
            generateParenthesisRecursive(n, parenthesis, prefix + "(", l + 1, r);
        }
        if (l > r) {
            generateParenthesisRecursive(n, parenthesis, prefix + ")", l, r + 1);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> parenthesis;
        generateParenthesisRecursive(n, parenthesis, "", 0, 0);
        return parenthesis;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testGenerateParentheses, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.generateParenthesis(3),
        std::vector<std::string>(
            {"((()))",
             "(()())",
             "(())()",
             "()(())",
             "()()()"}));
}
