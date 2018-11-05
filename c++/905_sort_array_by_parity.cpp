#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            while (l < r && nums[l] % 2 == 0) {
                l++;
            }
            std::swap(nums[l], nums[r]);
            while (l < r && nums[r] % 2 != 0) {
                r--;
            }
            std::swap(nums[l], nums[r]);
        }
        return nums;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
