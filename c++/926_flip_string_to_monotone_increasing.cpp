#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
    int minFlipsMonoIncrRecursive(const std::string& str, int i, const std::vector<int>& numOfOnes) {
        if (i == 0) {
            return 0;
        }
        if (str[i] == '1') {
            return minFlipsMonoIncrRecursive(str, i - 1, numOfOnes);
        }
        return std::min(minFlipsMonoIncrRecursive(str, i - 1, numOfOnes) + 1, numOfOnes[i]);
    }

   public:
    int minFlipsMonoIncr(const std::string& str) {
        if (str.empty()) {
            return 0;
        }
        std::vector<int> numOfOnes(str.length(), 0);
        numOfOnes[0] = (str[0] == '1');
        for (int i = 1; i < str.length(); i++) {
            numOfOnes[i] = numOfOnes[i - 1] + (str[i] == '1');
        }
        return minFlipsMonoIncrRecursive(str, str.length() - 1, numOfOnes);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.minFlipsMonoIncr("010110"), 2);
    EXPECT_EQ(solution.minFlipsMonoIncr("00011000"), 2);
}