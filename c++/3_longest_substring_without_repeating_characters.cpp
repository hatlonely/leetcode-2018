#include <gtest/gtest.h>
#include <bitset>
#include <string>

class Solution {
   public:
    int lengthOfLongestSubstring(const std::string& str) {
        std::bitset<256> bs;

        int idx1 = 0;
        int idx2 = 0;
        int len  = str.length();
        int max  = 0;
        while (idx1 < len && idx2 < len) {
            while (!bs.test(str[idx2]) && idx2 < len) {
                bs.set(str[idx2], true);
                idx2++;
            }
            max = std::max(max, idx2 - idx1);
            while (idx1 < idx2 && str[idx1] != str[idx2]) {
                bs.set(str[idx1], false);
                idx1++;
            }
            idx1++;
            bs.set(str[idx2], false);
        }

        return max;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testLongestSubstringWithoutRepeatingCharacters, case1) {
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}
