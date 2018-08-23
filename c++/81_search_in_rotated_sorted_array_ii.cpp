#include <gtest/gtest.h>

class Solution {
   public:
    bool searchRecursive(const std::vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return false;
        }

        int m = (l + r) / 2;
        if (nums[m] == target) {
            return true;
        }

        if (nums[l] < nums[m]) {
            if (nums[l] <= target && target < nums[m]) {
                return searchRecursive(nums, target, l, m - 1);
            }
            return searchRecursive(nums, target, m + 1, r);
        }

        if (nums[m] < nums[r]) {
            if (nums[m] < target && target <= nums[r]) {
                return searchRecursive(nums, target, m + 1, r);
            }
            return searchRecursive(nums, target, l, m - 1);
        }

        if (searchRecursive(nums, target, l, m - 1)) {
            return true;
        }

        return searchRecursive(nums, target, m + 1, r);
    }

    bool search(const std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }

        return searchRecursive(nums, target, 0, nums.size() - 1);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.search({2, 5, 6, 0, 0, 1, 2}, 2));
}