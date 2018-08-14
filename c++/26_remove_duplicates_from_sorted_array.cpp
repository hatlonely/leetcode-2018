#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        size_t idx = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[idx]) {
                nums[++idx] = nums[i];
            }
        }
        return idx + 1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testRemoveDuplicatesFromSortedArray, case1) {
    Solution solution;
    auto     nums = std::vector<int>({1, 1, 2});
    EXPECT_EQ(solution.removeDuplicates(nums), 2);
    EXPECT_EQ(nums[0], 1);
    EXPECT_EQ(nums[1], 2);
}