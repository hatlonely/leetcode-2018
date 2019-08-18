#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int countCharacters(const std::vector<std::string>& words, const std::string chars) {
        int              sum = 0;
        std::vector<int> vc(26, 0);
        for (auto ch : chars) {
            vc[ch - 'a']++;
        }
        for (auto& word : words) {
            int i = 0;
            for (; i < word.length(); i++) {
                auto ch = word[i];
                if (vc[ch - 'a'] == 0) {
                    break;
                } else {
                    vc[ch - 'a']--;
                }
            }
            if (i == word.length()) {
                sum += word.length();
            }
            for (; i > 0; i--) {
                auto ch = word[i - 1];
                vc[ch - 'a']++;
            }
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case5048) {
    Solution solution;
    EXPECT_EQ(solution.countCharacters({"cat", "bt", "hat", "tree"}, "atach"), 6);
    EXPECT_EQ(solution.countCharacters({"hello", "world", "leetcode"}, "welldonehoneyr"), 10);
}
