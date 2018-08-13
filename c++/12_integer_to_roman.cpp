#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

const std::unordered_map<int, std::string> kIntRomanMap = {
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"},
    {10, "X"},
    {20, "XX"},
    {30, "XXX"},
    {40, "XL"},
    {50, "L"},
    {60, "LX"},
    {70, "LXX"},
    {80, "LXXX"},
    {90, "XC"},
    {100, "C"},
    {200, "CC"},
    {300, "CCC"},
    {400, "CD"},
    {500, "D"},
    {600, "DC"},
    {700, "DCC"},
    {800, "DCCC"},
    {900, "CM"},
    {1000, "M"},
    {2000, "MM"},
    {3000, "MMM"},
};

class Solution {
   public:
    std::string intToRoman(int num) {
        std::string roman = "";
        for (int i = 1000; i > 0; i /= 10) {
            auto n = (num / i) * i;
            if (n != 0) {
                roman += kIntRomanMap.at(n);
            }
            num -= n;
        }
        return roman;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testIntegerToRoman, case1) {
    Solution solution;
    EXPECT_EQ(solution.intToRoman(3), "III");
    EXPECT_EQ(solution.intToRoman(4), "IV");
    EXPECT_EQ(solution.intToRoman(9), "IX");
    EXPECT_EQ(solution.intToRoman(58), "LVIII");
    EXPECT_EQ(solution.intToRoman(1994), "MCMXCIV");
}
