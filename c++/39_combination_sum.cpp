#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& nums, int num) {
        if (num == 0) {
            return {{}};
        }
        if (nums.empty()) {
            return {};
        }
        int  m            = 0;
        auto combinations = std::vector<std::vector<int>>();
        while (true) {
            if (num < 0) {
                break;
            }
            for (auto c : combinationSum(std::vector<int>(nums.begin() + 1, nums.end()), num)) {
                for (int i = 0; i < m; i++) {
                    c.emplace_back(nums[0]);
                }
                combinations.emplace_back(c);
            }
            num -= nums[0];
            m++;
        }

        return combinations;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.combinationSum({2, 3, 6, 7, 8}, 7),
              std::vector<std::vector<int>>({{7}, {3, 2, 2}}));
    EXPECT_EQ(solution.combinationSum({2, 3, 5}, 8),
              std::vector<std::vector<int>>({{5, 3}, {3, 3, 2}, {2, 2, 2, 2}}));
}