#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int oddEvenJumps(const std::vector<int>& nums) {
        int               n = nums.size();
        std::vector<bool> canJumpOdd(nums.size(), false);
        std::vector<bool> canJumpEven(n, false);
        canJumpOdd[n - 1]  = true;
        canJumpEven[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            auto ltIdx = -1;
            auto gtIdx = -1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    ltIdx = j;
                    gtIdx = j;
                    break;
                }
                if (nums[j] > nums[i] && (gtIdx == -1 || nums[j] < nums[gtIdx])) {
                    gtIdx = j;
                }
                if (nums[j] < nums[i] && (ltIdx == -1 || nums[j] > nums[ltIdx])) {
                    ltIdx = j;
                }
            }
            canJumpEven[i] = ltIdx == -1 ? false : canJumpOdd[ltIdx];
            canJumpOdd[i]  = gtIdx == -1 ? false : canJumpEven[gtIdx];
        }

        auto count = 0;
        for (auto canJump : canJumpOdd) {
            if (canJump) {
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.oddEvenJumps({5, 1, 3, 4, 2}), 3);
    EXPECT_EQ(solution.oddEvenJumps({2, 3, 1, 1, 4}), 3);
    EXPECT_EQ(solution.oddEvenJumps({10, 13, 12, 14, 15}), 2);
}
