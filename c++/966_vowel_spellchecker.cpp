#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

const std::unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});

class Solution {
    void wordmap(
        const std::vector<std::string>&               wordlist,
        std::unordered_set<std::string>&              wordset,
        std::unordered_map<std::string, std::string>& lowermap,
        std::unordered_map<std::string, std::string>& likemap) {
        for (const auto word : wordlist) {
            auto wordCopy = word;
            wordset.insert(word);
            for (int i = 0; i < wordCopy.length(); i++) {
                wordCopy[i] = ::tolower(word[i]);
            }
            if (lowermap.count(wordCopy) == 0) {
                lowermap[wordCopy] = word;
            }
            for (int i = 0; i < wordCopy.length(); i++) {
                if (vowels.count(wordCopy[i]) > 0) {
                    wordCopy[i] = '*';
                }
            }
            if (likemap.count(wordCopy) == 0) {
                likemap[wordCopy] = word;
            }
        }
    }

   public:
    std::vector<std::string> spellchecker(
        const std::vector<std::string>& wordlist,
        const std::vector<std::string>& queries) {
        std::vector<std::string>                     result;
        std::unordered_set<std::string>              wordset;
        std::unordered_map<std::string, std::string> lowermap;
        std::unordered_map<std::string, std::string> likemap;
        wordmap(wordlist, wordset, lowermap, likemap);
        for (auto query : queries) {
            if (wordset.count(query) > 0) {
                result.push_back(query);
                continue;
            }
            for (int i = 0; i < query.length(); i++) {
                query[i] = ::tolower(query[i]);
            }
            if (lowermap.count(query) > 0) {
                result.push_back(lowermap[query]);
                continue;
            }
            for (int i = 0; i < query.length(); i++) {
                if (vowels.count(query[i]) > 0) {
                    query[i] = '*';
                }
            }
            if (likemap.count(query) > 0) {
                result.push_back(likemap[query]);
                continue;
            }
            result.push_back("");
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.spellchecker(
                  {"KiTe", "kite", "hare", "Hare"},
                  {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"}),
              std::vector<std::string>({
                  "kite",
                  "KiTe",
                  "KiTe",
                  "Hare",
                  "hare",
                  "",
                  "",
                  "KiTe",
                  "",
                  "KiTe",
              }));
}