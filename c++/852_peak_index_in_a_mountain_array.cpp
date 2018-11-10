#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int peakIndexInMountainArray(std::vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (nums[m] < nums[m + 1]) {
                i = m + 1;
            } else {
                j = m;
            }
        }

        return i;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}