#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int movesToMakeZigzag(std::vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;

        auto nums1 = std::vector<int>(nums);
        for (int i = 0; i < nums1.size(); i += 2) {
            if (i - 1 >= 0 && nums1[i] <= nums1[i - 1]) {
                count1 += nums1[i - 1] - nums1[i] + 1;
                nums1[i - 1] = nums1[i] - 1;
            }
            if (i + 1 < nums1.size() && nums1[i] <= nums1[i + 1]) {
                count1 += nums1[i + 1] - nums1[i] + 1;
                nums1[i + 1] = nums1[i] - 1;
            }
        }

        auto nums2 = std::vector<int>(nums);
        for (int i = 1; i < nums2.size(); i += 2) {
            if (i - 1 >= 0 && nums2[i] <= nums2[i - 1]) {
                count2 += nums2[i - 1] - nums2[i] + 1;
                nums2[i - 1] = nums2[i] - 1;
            }
            if (i + 1 < nums2.size() && nums2[i] <= nums2[i + 1]) {
                count2 += nums2[i + 1] - nums2[i] + 1;
                nums2[i + 1] = nums2[i] - 1;
            }
        }

        return count1 < count2 ? count1 : count2;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     vi1 = std::vector<int>({1, 2, 3});
    EXPECT_EQ(solution.movesToMakeZigzag(vi1), 2);

    auto vi2 = std::vector<int>({9, 6, 1, 6, 2});
    EXPECT_EQ(solution.movesToMakeZigzag(vi2), 4);
}
