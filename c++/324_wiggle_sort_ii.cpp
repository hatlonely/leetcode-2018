#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    void wiggleSort(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto numCopy = std::vector<int>(nums.size(), 0);
        auto n       = nums.size();
        auto m       = (n + 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                numCopy[i] = nums[i / 2];
            } else {
                numCopy[i] = nums[i / 2 + m];
            }
        }
        int split = 0;
        for (int i = 1; i < numCopy.size(); i++) {
            if (numCopy[i] == numCopy[i - 1]) {
                split = i;
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = numCopy[(i + split) % n];
        }
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({1, 5, 1, 1, 6, 4});
    solution.wiggleSort(nums);
    EXPECT_EQ(nums, std::vector<int>({1, 4, 1, 5, 1, 6}));
}