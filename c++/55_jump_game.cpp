#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    bool canJump(const std::vector<int>& nums) {
        int last = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = std::max(curr, nums[i] + i);
            if (i == last) {
                last = curr;
            } else if (i > last) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.canJump({2, 3, 1, 1, 4}));
    EXPECT_FALSE(solution.canJump({3, 2, 1, 0, 4}));
}