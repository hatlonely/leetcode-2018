#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class Solution {
   public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i + 1] < m) {
                return false;
            }
            m = std::max(nums[i], m);
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
}