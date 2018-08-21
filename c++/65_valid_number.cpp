#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    bool isNumber(const std::string& str) {
        int i = 0;
        int n = str.length();
        while (i < n && isspace(str[i])) {
            i++;
        }
        if (str[i] == '-' || str[i] == '+') {
            i++;
        }
        if (isdigit(str[i])) {
            while (i < n && isdigit(str[i])) {
                i++;
            }
            if (str[i] == '.') {
                i++;
                while (i < n && isdigit(str[i])) {
                    i++;
                }
            }
        } else if (str[i] == '.') {
            i++;
            if (!isdigit(str[i])) {
                return false;
            }
            while (i < n && isdigit(str[i])) {
                i++;
            }
        } else {
            return false;
        }
        if (str[i] == 'e') {
            i++;
            if (str[i] == '-' || str[i] == '+') {
                i++;
            }
            if (!isdigit(str[i])) {
                return false;
            }
            while (i < n && isdigit(str[i])) {
                i++;
            }
        }
        while (i < n && isspace(str[i])) {
            i++;
        }
        return i == n;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isNumber("0"));
    EXPECT_TRUE(solution.isNumber("2e10"));
    EXPECT_TRUE(solution.isNumber(" 0.1 "));
    EXPECT_TRUE(solution.isNumber("1."));
    EXPECT_TRUE(solution.isNumber(".1"));
    EXPECT_TRUE(solution.isNumber("-1."));
    EXPECT_TRUE(solution.isNumber("+.8"));
    EXPECT_TRUE(solution.isNumber("+.8e-6"));
    EXPECT_FALSE(solution.isNumber("abc"));
    EXPECT_FALSE(solution.isNumber("1 a"));
    EXPECT_FALSE(solution.isNumber("1e"));
    EXPECT_FALSE(solution.isNumber("."));
}