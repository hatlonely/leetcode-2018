#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
    bool checkEqualParts(const std::vector<int>& vi, int i1, int j1, int i2, int j2) {
        while (j2 > i2 && j1 > i1) {
            if (vi[--j2] != vi[--j1]) {
                return false;
            }
        }
        return true;
    }

   public:
    std::vector<int> threeEqualParts(const std::vector<int>& vi) {
        int numOfOne = 0;
        for (int i = 0; i < vi.size(); i++) {
            if (vi[i] == 1) {
                numOfOne++;
            }
        }
        if (numOfOne % 3 != 0) {
            return {-1, -1};
        }
        if (numOfOne == 0) {
            return {0, 0};
        }

        int l = numOfOne / 3;
        int i = 0;
        int m = 0;
        int n = 0;
        for (; i < vi.size();) {
            if (vi[i++] == 1) {
                m++;
                if (m == l) {
                    m = i;
                    break;
                }
            }
        }
        for (; i < vi.size();) {
            if (vi[i++] == 1) {
                n++;
                if (n == l) {
                    n = i;
                    break;
                }
            }
        }

        int lastZeroLen = 0;
        while (vi[vi.size() - lastZeroLen - 1] == 0) {
            lastZeroLen++;
        }
        m += lastZeroLen;
        n += lastZeroLen;
        if (!checkEqualParts(vi, 0, m, m, n) || !checkEqualParts(vi, m, n, n, vi.size())) {
            return {-1, -1};
        }

        return {m - 1, n};
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.threeEqualParts({1, 0, 1, 0, 1}), std::vector<int>({0, 3}));
    EXPECT_EQ(solution.threeEqualParts({1, 0, 1, 0, 1, 0}), std::vector<int>({1, 4}));
}