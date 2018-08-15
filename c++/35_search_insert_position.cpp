#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int searchInsert(const std::vector<int>& nums, int num) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > num) {
                r = m - 1;
            } else if (nums[m] < num) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return l;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.searchInsert({1, 3, 5, 6}, 5), 2);
    EXPECT_EQ(solution.searchInsert({1, 3, 5, 6}, 2), 1);
    EXPECT_EQ(solution.searchInsert({1, 3, 5, 6}, 7), 4);
    EXPECT_EQ(solution.searchInsert({1, 3, 5, 6}, 0), 0);
}
