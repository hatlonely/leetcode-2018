#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int ordinalOfDate(std::string date) {
        static const auto days = std::vector<int>({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});

        int year  = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day   = std::stoi(date.substr(8, 2));

        for (int i = 0; i < month; i++) {
            day += days[i];
        }
        if ((month > 2) && ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))) {
            day += 1;
        }

        return day;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, test1) {
    Solution solution;
    EXPECT_EQ(solution.ordinalOfDate("2019-01-09"), 9);
    EXPECT_EQ(solution.ordinalOfDate("2019-02-10"), 41);
    EXPECT_EQ(solution.ordinalOfDate("2003-03-01"), 60);
    EXPECT_EQ(solution.ordinalOfDate("2004-03-01"), 61);
    EXPECT_EQ(solution.ordinalOfDate("2016-02-29"), 60);
    EXPECT_EQ(solution.ordinalOfDate("2016-01-31"), 31);
}