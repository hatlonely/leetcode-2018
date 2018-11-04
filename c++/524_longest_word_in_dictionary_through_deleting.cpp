#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::string findLongestWord(std::string s, std::vector<std::string>& d) {
        std::string word;
        for (auto& w : d) {
            if (w.size() < word.size() || (w.size() == word.size() && w > word)) {
                continue;
            }
            int i = 0;
            int j = 0;
            while (i < w.size() && j < s.size()) {
                if (w[i] == s[j]) {
                    i++;
                }
                j++;
            }
            if (i == w.size()) {
                word = w;
            }
        }
        return word;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     d = std::vector<std::string>({"ale", "apple", "monkey", "plea"});
    EXPECT_EQ(solution.findLongestWord("abpcplea", d), "apple");
}