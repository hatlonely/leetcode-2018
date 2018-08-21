#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    std::string getPermutation(int n, int k) {
        k--;
        std::string permutation(n, '1');
        int         fac = 1;
        for (int i = 1; i < n; i++) {
            permutation[i] = '1' + i;
            fac *= i;
        }

        int idx = 0;
        while (k > 0) {
            if (k >= fac) {
                int temp         = permutation[idx];
                int startIdx     = idx + 1;
                int endIdx       = k / fac + idx;
                permutation[idx] = permutation[endIdx];
                while (temp > permutation[startIdx]) {
                    startIdx++;
                }
                for (; endIdx > startIdx; endIdx--) {
                    permutation[endIdx] = permutation[endIdx - 1];
                }
                permutation[startIdx] = temp;
            }
            k %= fac;
            fac /= (n - idx - 1);
            idx++;
        }
        return permutation;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testPermutationSequence, case1) {
    Solution solution;
    EXPECT_EQ(solution.getPermutation(3, 1), "123");
    EXPECT_EQ(solution.getPermutation(3, 2), "132");
    EXPECT_EQ(solution.getPermutation(3, 3), "213");
    EXPECT_EQ(solution.getPermutation(3, 4), "231");
    EXPECT_EQ(solution.getPermutation(3, 5), "312");
    EXPECT_EQ(solution.getPermutation(3, 6), "321");
    EXPECT_EQ(solution.getPermutation(4, 9), "2314");
}