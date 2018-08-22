#include <gtest/gtest.h>
#include <bitset>
#include <limits>
#include <string>
#include <unordered_map>

class Solution {
   public:
    std::string minWindow(const std::string& s, const std::string& t) {
        std::unordered_map<char, int> charTimesMap;
        std::unordered_map<char, int> originCharTimesMap;
        for (auto ch : t) {
            charTimesMap[ch] = 0;
            if (originCharTimesMap.count(ch) == 0) {
                originCharTimesMap[ch] = 1;
            } else {
                originCharTimesMap[ch]++;
            }
        }
        int i      = 0;
        int j      = 0;
        int n      = 0;
        int l      = 0;
        int r      = 0;
        int minLen = std::numeric_limits<int>::max();
        while (i < s.length()) {
            for (; j < s.length(); j++) {
                if (charTimesMap.count(s[j]) == 0) {
                    continue;
                }
                charTimesMap[s[j]]++;
                if (charTimesMap[s[j]] <= originCharTimesMap[s[j]]) {
                    n++;
                    if (n == t.size()) {
                        break;
                    }
                }
            }
            for (; i < j; i++) {
                if (charTimesMap.count(s[i]) == 0) {
                    continue;
                }
                if (charTimesMap[s[i]] == originCharTimesMap[s[i]]) {
                    break;
                }
                charTimesMap[s[i]]--;
            }

            if (n != t.size()) {
                break;
            }
            if (minLen > j - i) {
                minLen = j - i;
                l      = i;
                r      = j;
            }
            for (; i < j; i++) {
                if (charTimesMap.count(s[i]) == 0) {
                    continue;
                }
                charTimesMap[s[i]]--;
                if (charTimesMap[s[i]] == originCharTimesMap[s[i]] - 1) {
                    n--;
                    break;
                }
            }
            i++;
            j++;
        }
        if (minLen > s.length()) {
            return "";
        }
        return s.substr(l, r - l + 1);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.minWindow("ADOBECODEBANC", "ABC"), "BANC");
    EXPECT_EQ(solution.minWindow("aa", "a"), "a");
    EXPECT_EQ(solution.minWindow("a", "aa"), "");
    EXPECT_EQ(solution.minWindow("aa", "aa"), "aa");
    EXPECT_EQ(solution.minWindow("bbaac", "aba"), "baa");
    EXPECT_EQ(solution.minWindow("acbdbaab", "aabd"), "dbaa");
}