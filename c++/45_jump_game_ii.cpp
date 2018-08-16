#include <gtest/gtest.h>
#include <limits>
#include <vector>

class Solution {
   public:
    int jump(const std::vector<int>& nums) {
        int step = 0;
        int last = 0;
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > last) {
                last = curr;
                step++;
            }
            curr = std::max(nums[i] + i, curr);
        }

        return step;
    }
};

class Solution1 {
   public:
    int jump(const std::vector<int>& nums) {
        auto jumps = std::vector<int>(nums.size(), std::numeric_limits<int>::max());
        jumps[0]   = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] < nums[i - 1]) {
                continue;
            }
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                jumps[i + j] = std::min(jumps[i] + 1, jumps[i + j]);
            }
        }

        return jumps.back();
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.jump({2, 3, 1, 1, 4}), 2);
    EXPECT_EQ(solution.jump({0}), 0);
    EXPECT_EQ(solution.jump({1, 1}), 1);
    EXPECT_EQ(solution.jump({1, 2, 3}), 2);
}