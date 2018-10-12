#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> subsetsWithDup(const std::vector<int>& nums) {
        std::map<int, int> numTimesMap;
        for (auto& num : nums) {
            numTimesMap[num]++;
        }
        int n = 0;
        for (auto& numTimes : numTimesMap) {
            n *= (numTimes.second + 1);
        }
        std::vector<std::vector<int>> subsets = {{}};
        subsets.reserve(n);
        for (auto& numTimes : numTimesMap) {
            int len = subsets.size();
            for (int i = 0; i < numTimes.second; i++) {
                for (int i = 0; i < len; i++) {
                    subsets.emplace_back(subsets[i]);
                    subsets[i].push_back(numTimes.first);
                }
            }
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