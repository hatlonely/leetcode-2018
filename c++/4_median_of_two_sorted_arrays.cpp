#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    int findKthSortedArrays(
        std::vector<int>& nums1, int m1, int n1,
        std::vector<int>& nums2, int m2, int n2,
        int k) {
        if (n1 - m1 > n2 - m2) {
            return findKthSortedArrays(nums2, m2, n2, nums1, m1, n1, k);
        }
        int k1 = std::min(k / 2, n1 - m1);
        int k2 = k - k1;
        if (m1 == n1) {
            return nums2[m2 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[m1], nums2[m2]);
        }
        if (nums1[m1 + k1 - 1] < nums2[m2 + k2 - 1]) {
            return findKthSortedArrays(nums1, m1 + k1, n1, nums2, m2, m2 + k2, k2);
        }
        if (nums1[m1 + k1 - 1] > nums2[m2 + k2 - 1]) {
            return findKthSortedArrays(nums1, m1, m1 + k1, nums2, m2 + k2, n2, k1);
        }
        return nums1[m1 + k1 - 1];
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        auto len1 = nums1.size();
        auto len2 = nums2.size();
        if ((len1 + len2) % 2 == 0) {
            auto m1 = findKthSortedArrays(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2);
            auto m2 = findKthSortedArrays(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2 + 1);
            return double(m1 + m2) / 2.0;
        }
        return double(findKthSortedArrays(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2 + 1));
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMedianOfTwoSortedArrays, case1) {
    Solution         solution;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.0);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 1, 1), 1);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 1, 2), 2);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 1, 3), 3);
}

TEST(testMedianOfTwoSortedArrays, case2) {
    Solution         solution;
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.5);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 2, 1), 1);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 2, 2), 2);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 2, 3), 3);
    EXPECT_EQ(solution.findKthSortedArrays(nums1, 0, 2, nums2, 0, 2, 4), 4);
}
