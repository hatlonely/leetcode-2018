#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int maxArea(const std::vector<int>& nums) {
        int idx1 = 0;
        int idx2 = nums.size() - 1;
        int aera = 0;
        while (idx1 < idx2) {
            if (nums[idx1] < nums[idx2]) {
                aera = std::max(aera, nums[idx1] * (idx2 - idx1));
                idx1++;
            } else {
                aera = std::max(aera, nums[idx2] * (idx2 - idx1));
                idx2--;
            }
        }
        return aera;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testContainerWithMostWater, case1) {
    Solution solution;
    EXPECT_EQ(solution.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}), 49);
}