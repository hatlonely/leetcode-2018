#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int trap(const std::vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int sum = 0;
        while (l < r) {
            while (l < r && nums[l] <= nums[l + 1]) {
                l++;
            }
            while (l < r && nums[r] <= nums[r - 1]) {
                r--;
            }
            if (nums[l] <= nums[r]) {
                int i = 1;
                while (l < r && nums[l] > nums[l + i]) {
                    sum += nums[l] - nums[l + i];
                    i++;
                }
                l += i;
            } else {
                int j = 1;
                while (l < r && nums[r] > nums[r - j]) {
                    sum += nums[r] - nums[r - j];
                    j++;
                }
                r -= j;
            }
        }

        return sum;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}), 6);
}