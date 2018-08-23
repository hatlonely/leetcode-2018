#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        auto sets   = subsets(std::vector<int>(nums.begin() + 1, nums.end()));
        auto result = std::vector<std::vector<int>>();
        for (auto& set : sets) {
            result.emplace_back(set);
            set.emplace_back(nums[0]);
            result.emplace_back(set);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.subsets({1, 2, 3}),
        std::vector<std::vector<int>>({{}, {1}, {2}, {2, 1}, {3}, {3, 1}, {3, 2}, {3, 2, 1}}));
}