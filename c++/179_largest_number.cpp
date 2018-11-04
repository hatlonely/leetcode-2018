#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Solution {
   public:
    std::string largestNumber(std::vector<int>& nums) {
        auto strs = std::vector<std::string>(nums.size(), "");
        std::transform(
            nums.begin(), nums.end(),
            strs.begin(),
            [](int num) {
                return std::to_string(num);
            });
        std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });

        if (strs[0] == "0") {
            return "0";
        }
        return std::accumulate(strs.begin(), strs.end(), std::string(""), [](const std::string& a, const std::string& b) {
            return a + b;
        });
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({3, 30, 34, 5, 9});
    EXPECT_EQ("9534330", solution.largestNumber(nums));
}

TEST(test, case2) {
    Solution solution;
    auto     nums = std::vector<int>({0, 0});
    EXPECT_EQ("0", solution.largestNumber(nums));
}