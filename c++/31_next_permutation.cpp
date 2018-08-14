#include <gtest/gtest.h>
#include <algorithm>

class SolutionStd {
   public:
    void nextPermutation(std::vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

class Solution {
   public:
    void nextPermutation(std::vector<int>& nums) {
        int idx = nums.size() - 1;
        while (idx > 0 && nums[idx] <= nums[idx - 1]) {
            idx--;
        }
        std::reverse(nums.begin() + idx, nums.end());
        if (idx == 0) {
            return;
        };
        std::swap(nums[idx - 1], *std::upper_bound(nums.begin() + idx, nums.end(), nums[idx - 1]));
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testNextPermutation, case1) {
    Solution solution;
    auto     nums = std::vector<int>({1, 2, 3});
    solution.nextPermutation(nums);
    EXPECT_EQ(nums, std::vector<int>({1, 3, 2}));
}

TEST(testNextPermutation, case2) {
    Solution solution;
    auto     nums = std::vector<int>({0, 1, 1, 0, 4, 4});
    solution.nextPermutation(nums);
    EXPECT_EQ(nums, std::vector<int>({0, 1, 1, 4, 0, 4}));
}
