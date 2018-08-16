#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    void permuteUniqueRecursive(
        const std::vector<int>&        numsUnique,
        const int                      n,
        std::vector<std::vector<int>>& permutations,
        std::vector<int>&              permutation,
        std::vector<int>&              times) {
        if (permutation.size() == n) {
            permutations.emplace_back(permutation);
        }
        for (int i = 0; i < numsUnique.size(); i++) {
            if (times[i] == 0) {
                continue;
            }
            times[i]--;
            permutation.emplace_back(numsUnique[i]);
            permuteUniqueRecursive(numsUnique, n, permutations, permutation, times);
            permutation.pop_back();
            times[i]++;
        }
    }

    std::vector<std::vector<int>> permuteUnique(const std::vector<int>& nums) {
        std::vector<std::vector<int>> permutations;
        std::vector<int>              permutation;

        std::unordered_map<int, int> numTimesMap;
        for (auto num : nums) {
            if (numTimesMap.count(num) == 0) {
                numTimesMap[num] = 1;
            } else {
                numTimesMap[num]++;
            }
        }
        std::vector<int> numsUnique(numTimesMap.size());
        std::vector<int> times(numTimesMap.size());
        int              i = 0;
        for (const auto& numTimes : numTimesMap) {
            numsUnique[i] = numTimes.first;
            times[i++]    = numTimes.second;
        }

        permuteUniqueRecursive(numsUnique, nums.size(), permutations, permutation, times);

        return permutations;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums         = std::vector<int>({1, 1, 2});
    auto     permutations = std::vector<std::vector<int>>(
        {{2, 1, 1},
         {1, 2, 1},
         {1, 1, 2}});
    EXPECT_EQ(solution.permuteUnique(nums), permutations);
}