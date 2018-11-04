#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maximumGap(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int max = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            max = std::max(max, nums[i + 1] - nums[i]);
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({3, 6, 9, 1});
    EXPECT_EQ(solution.maximumGap(nums), 3);
}