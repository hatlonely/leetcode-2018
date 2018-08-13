#include <gtest/gtest.h>
#include <limits>
#include <string>

class Solution {
   public:
    int myAtoi(const std::string& str) {
        size_t  idx      = 0;
        size_t  len      = str.length();
        bool    negative = false;
        int64_t result   = 0;

        while (idx < len && isspace(str[idx])) {
            idx++;
        }

        if (idx < len) {
            if (str[idx] == '-') {
                negative = true;
                idx++;
            } else if (str[idx] == '+') {
                idx++;
            }
        }

        while (idx < len && isdigit(str[idx])) {
            result *= 10;
            result += str[idx] - '0';
            if (result >= 2147483648) {
                break;
            }
            idx++;
        }

        if (negative) {
            result = std::max(-result, (int64_t)std::numeric_limits<int32_t>::min());
        } else {
            result = std::min(result, (int64_t)std::numeric_limits<int32_t>::max());
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testAtoi, case1) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("42"), 42);
    EXPECT_EQ(solution.myAtoi("   -42"), -42);
    EXPECT_EQ(solution.myAtoi("4193 with words"), 4193);
    EXPECT_EQ(solution.myAtoi("words and 987"), 0);
    EXPECT_EQ(solution.myAtoi("-91283472332"), -2147483648);
    EXPECT_EQ(solution.myAtoi("+1"), 1);
}
