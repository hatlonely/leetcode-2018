#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::string largestTimeFromDigits(std::vector<int>& nums) {
        auto greater = std::greater<int>();
        std::sort(nums.begin(), nums.end(), greater);

        do {
            if (nums[0] * 10 + nums[1] >= 24) {
                continue;
            }
            if (nums[2] * 10 + nums[3] >= 60) {
                continue;
            }
            std::string str = "00:00";
            str[0] += nums[0];
            str[1] += nums[1];
            str[3] += nums[2];
            str[4] += nums[3];
            return str;
        } while (std::next_permutation(nums.begin(), nums.end(), greater));

        return "";
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({3, 2, 9, 5});
    EXPECT_EQ(solution.largestTimeFromDigits(nums), "23:59");
}