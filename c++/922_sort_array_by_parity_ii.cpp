#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        while (true) {
            while (i < n && nums[i] % 2 == 0) {
                i += 2;
            }
            while (j < n && nums[j] % 2 != 0) {
                j += 2;
            }
            if (i >= n || j >= n) {
                break;
            }
            std::swap(nums[i], nums[j]);
        }

        return nums;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
