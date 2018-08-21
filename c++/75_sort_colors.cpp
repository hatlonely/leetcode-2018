#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    void sortColors(std::vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            while (l < r && nums[l] == 0) {
                l++;
            }
            while (l < r && nums[r] == 2) {
                r--;
            }
            if (i > l && nums[i] == 0) {
                std::swap(nums[i], nums[l++]);
            } else if (i < r && nums[i] == 2) {
                std::swap(nums[i], nums[r--]);
            }
            if (i > l && nums[i] == 0) {
                std::swap(nums[i], nums[l++]);
            } else if (i < r && nums[i] == 2) {
                std::swap(nums[i], nums[r--]);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({2, 0, 2, 1, 1, 0});
    solution.sortColors(nums);
    EXPECT_EQ(nums, std::vector<int>({0, 0, 1, 1, 2, 2}));
}

TEST(test, case2) {
    Solution solution;
    auto     nums = std::vector<int>({2, 0, 1});
    solution.sortColors(nums);
    EXPECT_EQ(nums, std::vector<int>({0, 1, 2}));
}

TEST(test, case3) {
    Solution solution;
    auto     nums = std::vector<int>({1, 2, 0});
    solution.sortColors(nums);
    EXPECT_EQ(nums, std::vector<int>({0, 1, 2}));
}
