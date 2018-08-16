#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    void permuteRecursive(
        const std::vector<int>&        nums,
        std::vector<std::vector<int>>& permutations,
        std::vector<int>&              permutation,
        std::vector<bool>&             choose) {
        if (permutation.size() == nums.size()) {
            permutations.emplace_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (choose[i]) {
                continue;
            }
            choose[i] = true;
            permutation.emplace_back(nums[i]);
            permuteRecursive(nums, permutations, permutation, choose);
            permutation.pop_back();
            choose[i] = false;
        }
    }
    std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
        std::vector<std::vector<int>> permutations;
        std::vector<int>              permutation;
        std::vector<bool>             choose(nums.size(), false);
        permuteRecursive(nums, permutations, permutation, choose);
        return permutations;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums         = std::vector<int>({1, 2, 3});
    auto     permutations = std::vector<std::vector<int>>(
        {{1, 2, 3},
         {1, 3, 2},
         {2, 1, 3},
         {2, 3, 1},
         {3, 1, 2},
         {3, 2, 1}});
    EXPECT_EQ(solution.permute(nums), permutations);
}