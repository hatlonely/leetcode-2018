#include <gtest/gtest.h>
#include <limits>
#include <vector>

class Solution {
   public:
    int maxSubArray(const std::vector<int>& nums) {
        int sum = 0;
        int max = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            max = std::max(sum, max);
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
    EXPECT_EQ(solution.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(solution.maxSubArray({-1}), -1);
}
