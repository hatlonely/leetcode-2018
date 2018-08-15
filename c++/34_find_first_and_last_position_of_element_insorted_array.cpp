#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int binarySearch(const std::vector<int>& nums, int l, int r, int num) {
        auto m = (l + r) / 2;
        if (l > r) {
            return -1;
        }
        if (nums[m] > num) {
            return binarySearch(nums, l, m - 1, num);
        } else if (nums[m] < num) {
            return binarySearch(nums, m + 1, r, num);
        } else {
            return m;
        }
    }

    std::vector<int> searchRange(const std::vector<int>& nums, int num) {
        auto i = binarySearch(nums, 0, nums.size() - 1, num);
        int  l = i - 1;
        int  r = i + 1;
        while (l >= 0 && nums[l] == num) {
            l--;
        }
        while (r < nums.size() && nums[r] == num) {
            r++;
        }
        return std::vector<int>({l + 1, r - 1});
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.searchRange({5, 7, 7, 8, 8, 10}, 8), std::vector<int>({3, 4}));
    EXPECT_EQ(solution.searchRange({5, 7, 7, 8, 8, 10}, 6), std::vector<int>({-1, -1}));
    EXPECT_EQ(solution.searchRange({}, 0), std::vector<int>({-1, -1}));
}
