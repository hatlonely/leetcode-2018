#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int m = numeric_limits<int>::min();
        int n = numeric_limits<int>::max();
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            p *= nums[i];
            if (p != 0) {
                m = max(m, p);
                n = min(n, p);
            } else {
                m = max(m, 0);
                p = 1;
            }
        }
        p = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            p *= nums[i];
            if (p != 0) {
                m = max(m, p);
                n = min(n, p);
            } else {
                m = max(m, 0);
                p = 1;
            }
        }

        return m;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
}