#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int searchRecursive(const std::vector<int> nums, int l, int r, int num) {
        if (l > r) {
            return -1;
        }

        auto m = (l + r) / 2;
        if (nums[m] == num) {
            return m;
        }

        if (nums[l] <= nums[m]) {
            if (nums[l] <= num && nums[m] > num) {
                return searchRecursive(nums, l, m - 1, num);
            }
            return searchRecursive(nums, m + 1, r, num);
        }

        if (nums[m] < num && nums[r] >= num) {
            return searchRecursive(nums, m + 1, r, num);
        }
        return searchRecursive(nums, l, m - 1, num);
    }

    int search(const std::vector<int>& nums, int n) {
        return searchRecursive(nums, 0, nums.size() - 1, n);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testSearchInRotatedSortedArray, case1) {
    Solution solution;
    EXPECT_EQ(solution.search({4, 5, 6, 7, 0, 1, 2}, 0), 4);
    EXPECT_EQ(solution.search({4, 5, 6, 7, 0, 1, 2}, 3), -1);
    EXPECT_EQ(solution.search({5, 1, 3}, 5), 0);
}