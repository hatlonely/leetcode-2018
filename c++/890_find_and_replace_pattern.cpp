#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
        std::vector<std::string> result;
        for (auto& word : words) {
            auto vc1    = std::vector<char>(26, 0);
            auto vc2    = std::vector<char>(26, 0);
            bool isRank = true;
            for (int i = 0; i < word.size(); i++) {
                if (vc1[word[i] - 'a'] == 0 && vc2[pattern[i] - 'a'] == 0) {
                    vc1[word[i] - 'a']    = pattern[i];
                    vc2[pattern[i] - 'a'] = word[i];
                    continue;
                }
                if (vc1[word[i] - 'a'] != pattern[i] || vc2[pattern[i] - 'a'] != word[i]) {
                    isRank = false;
                    break;
                }
            }
            if (isRank) {
                result.emplace_back(word);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
