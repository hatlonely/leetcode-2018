#include <gtest/gtest.h>
#include <iostream>
#include <vector>

void reverse(std::vector<int>& nums, int k) {
    for (int i = 0; i <= k / 2; i++) {
        std::swap(nums[i], nums[k - i]);
    }
}

class Solution {
   public:
    std::vector<int> pancakeSort(std::vector<int>& nums) {
        std::vector<int> vi;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == i + 1) {
                continue;
            }
            int j = 0;
            for (; j < i && nums[j] != i + 1; j++) {
                // nothing to do
            }
            if (j > 0) {
                reverse(nums, j);
                vi.push_back(j + 1);
            }
            if (i > 0) {
                reverse(nums, i);
                vi.push_back(i + 1);
            }
        }
        return vi;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({3, 2, 4, 1});
    EXPECT_EQ(solution.pancakeSort(nums), std::vector<int>({3, 4, 2, 3, 2}));
}