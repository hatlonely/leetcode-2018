#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class Solution {
   public:
    int search(const vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                return m;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.search({-1, 0, 3, 5, 9, 12}, 9), 4);
    EXPECT_EQ(solution.search({-1, 0, 3, 5, 9, 12}, 2), -1);
}