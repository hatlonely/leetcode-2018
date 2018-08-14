#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        size_t idx = 0;
        for (const auto& num : nums) {
            if (num == val) {
                continue;
            }
            nums[idx++] = num;
        }
        return idx;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testRemoveElement, case1) {
    Solution solution;
    auto     nums = std::vector<int>({0, 1, 2, 2, 3, 0, 4, 2});
    EXPECT_EQ(solution.removeElement(nums, 2), 5);
    EXPECT_EQ(nums[0], 0);
    EXPECT_EQ(nums[1], 1);
    EXPECT_EQ(nums[2], 3);
    EXPECT_EQ(nums[3], 0);
    EXPECT_EQ(nums[4], 4);
}
