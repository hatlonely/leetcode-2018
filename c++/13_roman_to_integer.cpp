#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

const std::unordered_map<char, int> kRomanIntMap = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

class Solution {
   public:
    int romanToInt(const std::string& str) {
        int num = 0;
        for (size_t i = 0; i < str.length(); i++) {
            auto v1 = kRomanIntMap.at(str[i]);
            auto v2 = i == str.length() - 1 ? 0 : kRomanIntMap.at(str[i + 1]);
            if (v1 >= v2) {
                num += v1;
            } else {
                num -= v1;
            }
        }
        return num;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testRomanToInteger, case1) {
    Solution solution;
    EXPECT_EQ(solution.romanToInt("III"), 3);
    EXPECT_EQ(solution.romanToInt("IV"), 4);
    EXPECT_EQ(solution.romanToInt("IX"), 9);
    EXPECT_EQ(solution.romanToInt("LVIII"), 58);
    EXPECT_EQ(solution.romanToInt("MCMXCIV"), 1994);
}
