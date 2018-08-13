#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.empty()) {
            return std::vector<std::vector<int>>();
        }

        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size() - 1;) {
            size_t idx1 = 0;
            size_t idx2 = nums.size() - 1;
            while (idx1 < i && idx2 > i) {
                auto sum = nums[i] + nums[idx1] + nums[idx2];
                if (sum < 0) {
                    idx1++;
                    while (idx1 < i && nums[idx1] == nums[idx1 - 1]) {
                        idx1++;
                    }
                } else if (sum > 0) {
                    idx2--;
                    while (idx2 > i && nums[idx2] == nums[idx2 + 1]) {
                        idx2--;
                    }
                } else {
                    result.emplace_back(std::vector<int>({nums[idx1], nums[i], nums[idx2]}));
                    idx1++;
                    while (idx1 < i && nums[idx1] == nums[idx1 - 1]) {
                        idx1++;
                    }
                    idx2--;
                    while (idx2 > i && nums[idx2] == nums[idx2 + 1]) {
                        idx2--;
                    }
                }
            }
            if (i < nums.size() - 2 && nums[i] == nums[i + 1] && nums[i] != nums[i - 1]) {
                idx1 = i;
                i++;
                idx2 = nums.size() - 1;
                while (idx2 > i) {
                    auto sum = nums[i] + nums[idx1] + nums[idx2];
                    if (sum > 0) {
                        idx2--;
                        continue;
                    }
                    if (sum == 0) {
                        result.emplace_back(std::vector<int>({nums[idx1], nums[i], nums[idx2]}));
                    }
                    break;
                }
            }
            i++;
            while (i < nums.size() - 1 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testThreeSum, case1) {
    Solution solution;
    auto     nums   = std::vector<int>{-1, 0, 1, 2, -1, -4};
    auto     result = std::vector<std::vector<int>>{{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST(testThreeSum, case2) {
    Solution solution;
    auto     nums   = std::vector<int>{-1, 0, 0, 0, 1};
    auto     result = std::vector<std::vector<int>>{{-1, 0, 1}, {0, 0, 0}};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST(testThreeSum, case3) {
    Solution solution;
    auto     nums   = std::vector<int>{};
    auto     result = std::vector<std::vector<int>>{};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST(testThreeSum, case4) {
    Solution solution;
    auto     nums   = std::vector<int>{0, 0, 0};
    auto     result = std::vector<std::vector<int>>{{0, 0, 0}};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST(testThreeSum, case5) {
    Solution solution;
    auto     nums   = std::vector<int>{1, 1, -2};
    auto     result = std::vector<std::vector<int>>{{-2, 1, 1}};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST(testThreeSum, case6) {
    Solution solution;
    auto     nums   = std::vector<int>{-2, 0, 1, 1, 2};
    auto     result = std::vector<std::vector<int>>{{-2, 0, 2}, {-2, 1, 1}};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST(testThreeSum, case7) {
    Solution solution;
    auto     nums   = std::vector<int>{0, 0, 0, 0};
    auto     result = std::vector<std::vector<int>>{{0, 0, 0}};
    EXPECT_EQ(solution.threeSum(nums), result);
}
