#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> combinationSum2Recursive(
        const std::vector<int>& nums, int l, int num) {
        if (num == 0) {
            return {{}};
        }
        if (l >= nums.size()) {
            return {};
        }
        std::vector<std::vector<int>> combinations;

        int times = 1;
        while (l + times < nums.size() && nums[l] == nums[l + times]) {
            times++;
        }

        int m = 0;
        while (m <= times && num >= 0) {
            for (auto& c : combinationSum2Recursive(nums, l + times, num)) {
                for (int i = 0; i < m; i++) {
                    c.emplace_back(nums[l]);
                }
                combinations.emplace_back(c);
            }
            num -= nums[l];
            m++;
        }

        return combinations;
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int num) {
        std::sort(nums.begin(), nums.end());
        return combinationSum2Recursive(nums, 0, num);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    {
        auto nums         = std::vector<int>({10, 1, 2, 7, 6, 1, 5});
        auto combinations = std::vector<std::vector<int>>({{6, 2}, {7, 1}, {5, 2, 1}, {6, 1, 1}});
        EXPECT_EQ(solution.combinationSum2(nums, 8), combinations);
    }
    {
        auto nums         = std::vector<int>({1, 2});
        auto combinations = std::vector<std::vector<int>>({{1}});
        EXPECT_EQ(solution.combinationSum2(nums, 1), combinations);
    }
    {
        auto nums         = std::vector<int>({2, 5, 2, 1, 2});
        auto combinations = std::vector<std::vector<int>>({{5}, {2, 2, 1}});
        EXPECT_EQ(solution.combinationSum2(nums, 5), combinations);
    }
}