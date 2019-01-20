#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>

class Solution {
   public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int i = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            nums[i] = -nums[i];
        }

        std::reverse(nums.begin(), nums.begin() + i);
        std::inplace_merge(nums.begin(), nums.begin() + i, nums.end());

        std::transform(nums.begin(), nums.end(), nums.begin(), [](int x) {
            return x * x;
        });

        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));

        return nums;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({-4, -1, 0, 3, 10});
    EXPECT_EQ(solution.sortedSquares(nums), std::vector<int>({0, 1, 9, 16, 100}));
}
