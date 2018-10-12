#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m + n - 1;
        for (; i >= 0 && m > 0 && n > 0; i--) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[i] = nums1[--m];
            } else {
                nums1[i] = nums2[--n];
            }
        }
        for (; i >= 0 && m > 0; i--) {
            nums1[i] = nums1[--m];
        }
        for (; i >= 0 && n > 0; i--) {
            nums1[i] = nums2[--n];
        }
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution         solution;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    EXPECT_EQ(nums1, std::vector<int>({1, 2, 2, 3, 5, 6}));
}