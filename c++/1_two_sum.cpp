#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numIdxMap;
        for (int i = 0; i < nums.size(); i++) {
            auto num = nums[i];
            if (numIdxMap.count(target - num) > 0) {
                return std::vector<int>({numIdxMap[target - num], i});
            }
            numIdxMap[num] = i;
        }
        return std::vector<int>({-1, -1});
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testTwoSum, case1) {
    Solution         solution;
    std::vector<int> vs = {2, 7, 11, 15};
    EXPECT_EQ(solution.twoSum(vs, 9), std::vector<int>({0, 1}));
}