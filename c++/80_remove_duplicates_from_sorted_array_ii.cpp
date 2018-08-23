#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int num1 = nums[0];
        int num2 = nums[1];
        int idx  = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == num1) {
                continue;
            }
            nums[idx++] = nums[i];
            num1        = num2;
            num2        = nums[i];
        }
        return idx;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({0, 0, 1, 1, 1, 1, 2, 3, 3});
    EXPECT_EQ(solution.removeDuplicates(nums), 7);
    EXPECT_EQ(nums, std::vector<int>({0, 0, 1, 1, 2, 3, 3, 3, 3}));
}

TEST(test, case2) {
    Solution solution;
    auto     nums = std::vector<int>({1, 1, 1, 2, 2, 3});
    EXPECT_EQ(solution.removeDuplicates(nums), 5);
    EXPECT_EQ(nums, std::vector<int>({1, 1, 2, 2, 3, 3}));
}