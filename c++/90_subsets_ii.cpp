#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>

class Solution {
    void subsetsWithDupRecursive(std::vector<std::vector<int>>& subsets, int num, int times) {
        int len = subsets.size();
        for (int i = 0; i < times; i++) {
            for (int i = 0; i < len; i++) {
                subsets.emplace_back(subsets[i]);
                subsets[i].push_back(num);
            }
        }
    }

   public:
    std::vector<std::vector<int>> subsetsWithDup(const std::vector<int>& nums) {
        std::map<int, int> numTimesMap;
        for (auto& num : nums) {
            if (numTimesMap.count(num) == 0) {
                numTimesMap[num] = 1;
            } else {
                numTimesMap[num]++;
            }
        }
        int n = 0;
        for (auto& numTimes : numTimesMap) {
            n *= (numTimes.second + 1);
        }
        std::vector<std::vector<int>> subsets = {{}};
        subsets.reserve(n);
        for (auto& numTimes : numTimesMap) {
            subsetsWithDupRecursive(subsets, numTimes.first, numTimes.second);
        }

        return subsets;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.subsetsWithDup({1, 2, 2}), std::vector<std::vector<int>>({{1, 2, 2}, {2, 2}, {1}, {}, {1, 2}, {2}}));
}