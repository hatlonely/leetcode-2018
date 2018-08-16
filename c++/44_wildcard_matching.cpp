#include <gtest/gtest.h>
#include <array>
#include <bitset>
#include <string>

class Solution {
   public:
    bool isMatch(const std::string &s, const std::string &p) {
        auto                     source  = "$" + s + "$";
        auto                     pattern = "$" + p + "$";
        int                      lens    = (int)source.length();
        int                      lenp    = (int)pattern.length();
        int                      idxs    = 0;
        int                      idxp    = 0;
        std::vector<std::string> words;
        for (int i = 0; i < lenp; i++) {
            if (pattern[i] == '*') {
                words.push_back(pattern.substr(idxp, i - idxp));
                while (++i < lenp && pattern[i] == '*')
                    ;
                idxp = i;
            }
        }
        words.push_back(pattern.substr(idxp));

        int idxw = 0;
        while (idxs < lens) {
            std::string &word  = words[idxw];
            bool         match = true;
            for (int j = 0; j < word.length(); j++) {
                if (idxs + j < lens && word[j] != '?' && word[j] != source[idxs + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                idxw++;
                idxs += word.length();
                if (idxw == words.size()) {
                    return idxs == lens;
                }
            } else {
                idxs++;
            }
        }
        return false;
    }
};

class Solution1 {
   public:
    bool isMatchRecursive(
        std::vector<std::vector<bool>> &matches,
        const std::string &source, int idx1, const std::string &pattern, int idx2) {
        if (idx2 == pattern.length()) {
            return idx1 == source.length();
        }
        if (pattern[idx2] == '*') {
            for (; idx2 < pattern.length() && pattern[idx2] == '*'; idx2++) {
            }
            for (; idx1 <= source.length(); idx1++) {
                if (!matches[idx1][idx2]) {
                    continue;
                }
                if (isMatchRecursive(matches, source, idx1, pattern, idx2)) {
                    return true;
                } else {
                    matches[idx1][idx2] = false;
                }
            }
        }
        if (idx1 == source.length()) {
            return false;
        }
        if (source[idx1] != pattern[idx2] && pattern[idx2] != '?') {
            return false;
        }
        return isMatchRecursive(matches, source, idx1 + 1, pattern, idx2 + 1);
    }

    bool isMatch(const std::string &source, const std::string &pattern) {
        std::vector<std::vector<bool>> matches(source.length() + 1, std::vector<bool>(pattern.length() + 1, true));
        return isMatchRecursive(matches, source, 0, pattern, 0);
    }
};

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isMatch("aa", "*"));
    EXPECT_TRUE(solution.isMatch("adceb", "*a*b"));
    EXPECT_FALSE(solution.isMatch("cb", "?a"));
    EXPECT_FALSE(solution.isMatch("acdcb", "a*c?b"));
    EXPECT_FALSE(solution.isMatch("", "?"));
    EXPECT_TRUE(solution.isMatch("abefcdgiescdfimde", "ab*cd?i*de"));
    EXPECT_FALSE(solution.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));
    EXPECT_FALSE(solution.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
}
