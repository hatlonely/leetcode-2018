#include <gtest/gtest.h>
#include <algorithm>
#include <limits>
#include <vector>

class Solution {
   public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int rsum  = 0;
        int rdiff = std::numeric_limits<int>::max();
        for (int i = 0; i < nums.size() - 1; i++) {
            size_t idx1 = i + 1;
            size_t idx2 = nums.size() - 1;
            while (idx1 < idx2) {
                auto sum = nums[i] + nums[idx1] + nums[idx2];
                if (sum < target) {
                    idx1++;
                } else if (sum > target) {
                    idx2--;
                } else {
                    return target;
                }
                auto diff = std::abs(sum - target);
                if (diff < rdiff) {
                    rsum  = sum;
                    rdiff = diff;
                }
            }
        }
        return rsum;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testThreeSumClosest, case1) {
    Solution         solution;
    std::vector<int> nums({-1, 2, 1, -4});
    EXPECT_EQ(solution.threeSumClosest(nums, 1), 2);
}
