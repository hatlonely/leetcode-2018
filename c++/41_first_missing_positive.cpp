#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

class Solution {
   public:
    int firstMissingPositive(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    {
        auto nums = std::vector<int>({1, 2, 0});
        EXPECT_EQ(solution.firstMissingPositive(nums), 3);
    }
    {
        auto nums = std::vector<int>({1, 2, 3});
        EXPECT_EQ(solution.firstMissingPositive(nums), 4);
    }
    {
        auto nums = std::vector<int>({3, 4, -1, 1});
        EXPECT_EQ(solution.firstMissingPositive(nums), 2);
    }
    {
        auto nums = std::vector<int>({7, 8, 9, 11, 12});
        EXPECT_EQ(solution.firstMissingPositive(nums), 1);
    }
    {
        auto nums = std::vector<int>({1, 1});
        EXPECT_EQ(solution.firstMissingPositive(nums), 2);
    }
}