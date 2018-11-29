#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int minIncrementForUnique(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int k = nums[0];
        int m = 0;
        for (int i = 1; i < nums.size(); i++) {
            k++;
            if (k <= nums[i]) {
                k = nums[i];
            } else {
                m += k - nums[i];
            }
        }
        return m;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({
        3,
        2,
        1,
        2,
        1,
        7,
    });
    EXPECT_EQ(solution.minIncrementForUnique(nums), 6);
}
