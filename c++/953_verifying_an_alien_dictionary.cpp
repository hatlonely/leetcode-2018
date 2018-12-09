#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        std::string chVal(order.size(), '0');

        for (int i = 0; i < order.size(); i++) {
            auto ch         = order[i];
            chVal[ch - 'a'] = 'a' + i;
        }

        return std::is_sorted(words.begin(), words.end(), [&](const std::string& w1, const std::string& w2) {
            int i = 0;
            int j = 0;
            while (i < w1.size() && j < w2.size()) {
                if (w1[i] == w2[j]) {
                    i++;
                    j++;
                    continue;
                }
                return chVal[w1[i] - 'a'] < chVal[w2[j] - 'a'];
            }
            return w1.size() < w2.size();
        });
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     words = std::vector<std::string>({
        "word",
        "world",
        "row",
    });
    EXPECT_FALSE(solution.isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"));
}

TEST(test, case2) {
    Solution solution;
    auto     words = std::vector<std::string>({"apple", "app"});
    EXPECT_FALSE(solution.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"));
}

TEST(test, case3) {
    Solution solution;
    auto     words = std::vector<std::string>({"hello", "leetcode"});
    EXPECT_TRUE(solution.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"));
}
