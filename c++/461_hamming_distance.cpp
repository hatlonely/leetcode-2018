#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int z     = x ^ y;
        int count = 0;
        while (z != 0) {
            z &= z - 1;
            count += 1;
        }

        return count;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}