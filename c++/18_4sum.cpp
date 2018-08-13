#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return std::vector<std::vector<int>>();
        }

        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        size_t n = nums.size();
        for (size_t i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            for (size_t j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 2]) {
                    continue;
                }
                if (nums[j] != nums[i] && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                size_t idx1 = j + 1;
                size_t idx2 = n - 1;
                while (idx1 < idx2) {
                    auto sum = nums[i] + nums[j] + nums[idx1] + nums[idx2];
                    if (sum < target) {
                        idx1++;
                        while (idx1 < idx2 && nums[idx1] == nums[idx1 - 1]) {
                            idx1++;
                        }
                    } else if (sum > target) {
                        idx2--;
                        while (idx1 < idx2 && nums[idx2] == nums[idx2 + 1]) {
                            idx2--;
                        }
                    } else {
                        result.emplace_back(std::vector<int>({nums[i], nums[j], nums[idx1], nums[idx2]}));
                        idx1++;
                        idx2--;
                        while (idx1 < idx2 && nums[idx1] == nums[idx1 - 1]) {
                            idx1++;
                        }
                        while (idx1 < idx2 && nums[idx2] == nums[idx2 + 1]) {
                            idx2--;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testFourSum, case1) {
    Solution solution;
    auto     nums   = std::vector<int>({1, 0, -1, 0, -2, 2});
    auto     result = std::vector<std::vector<int>>({{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    EXPECT_EQ(solution.fourSum(nums, 0), result);
}

TEST(testFourSum, case2) {
    Solution solution;
    auto     nums   = std::vector<int>({});
    auto     result = std::vector<std::vector<int>>({});
    EXPECT_EQ(solution.fourSum(nums, 0), result);
}

TEST(testFourSum, case4) {
    Solution solution;
    auto     nums   = std::vector<int>({-3, -2, -1, 0, 0, 1, 2, 3});
    auto     result = std::vector<std::vector<int>>({{-3, -2, 2, 3}, {-3, -1, 1, 3}, {-3, 0, 0, 3}, {-3, 0, 1, 2}, {-2, -1, 0, 3}, {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    EXPECT_EQ(solution.fourSum(nums, 0), result);
}

TEST(testFourSum, case5) {
    Solution solution;
    auto     nums   = std::vector<int>({-1, 0, 1, 2, -1, -4});
    auto     result = std::vector<std::vector<int>>({{-4, 0, 1, 2}, {-1, -1, 0, 1}});
    EXPECT_EQ(solution.fourSum(nums, -1), result);
}

TEST(testFourSum, case6) {
    Solution solution;
    auto     nums   = std::vector<int>({-1, 0, -5, -2, -2, -4, 0, 1, -2});
    auto     result = std::vector<std::vector<int>>({{-5, -4, -1, 1}, {-5, -4, 0, 0}, {-5, -2, -2, 0}, {-4, -2, -2, -1}});
    EXPECT_EQ(solution.fourSum(nums, -9), result);
}

TEST(testFourSum, case8) {
    Solution solution;
    auto     nums   = std::vector<int>({0, 0, 0, 0});
    auto     result = std::vector<std::vector<int>>({{0, 0, 0, 0}});
    EXPECT_EQ(solution.fourSum(nums, 0), result);
}
