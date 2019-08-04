#include <gtest/gtest.h>
#include <iostream>

class Solution {
    int longestDecompositionRecursive(std::string text, int m, int n) {
        if (m > n) {
            return 0;
        }
        // [m:m+i] == [n-i:n]
        for (int i = 1; i <= (n - m + 1) / 2; i++) {
            bool isDecomposition = true;
            for (int k = 0; k < i; k++) {
                if (text[m + k] != text[n - i + 1 + k]) {
                    isDecomposition = false;
                }
            }

            if (isDecomposition) {
                return longestDecompositionRecursive(text, m + i, n - i) + 2;
            }
        }

        return 1;
    }

   public:
    int longestDecomposition(std::string text) {
        return longestDecompositionRecursive(text, 0, text.length() - 1);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi"), 7);
    EXPECT_EQ(solution.longestDecomposition("merchant"), 1);
    EXPECT_EQ(solution.longestDecomposition("antaprezatepzapreanta"), 11);
    EXPECT_EQ(solution.longestDecomposition("aaa"), 3);
    EXPECT_EQ(solution.longestDecomposition("elvtoelvto"), 2);
}
