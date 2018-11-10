#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> selfDividingNumbers(int l, int r) {
        std::vector<int> nums;
        for (int i = l; i <= r; i++) {
            int  n                = i;
            bool isDividingNumber = true;
            while (n != 0) {
                int m = n % 10;
                if (m == 0 || i % m != 0) {
                    isDividingNumber = false;
                    break;
                }
                n /= 10;
            }
            if (isDividingNumber) {
                nums.push_back(i);
            }
        }
        return nums;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}