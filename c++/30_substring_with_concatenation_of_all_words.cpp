#include <gtest/gtest.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> findSubstring(const std::string& source, const std::vector<std::string>& words) {
        if (words.empty()) {
            return std::vector<int>();
        }

        int  m            = words.size();
        int  n            = words[0].length();
        int  endIdx       = source.length() - m * n;
        auto indexs       = std::vector<int>();
        auto wordTimesMap = std::unordered_map<std::string, int>();
        auto st           = std::stack<std::string>();

        for (const auto& word : words) {
            if (wordTimesMap.count(word) == 0) {
                wordTimesMap[word] = 1;
            } else {
                wordTimesMap[word]++;
            }
        }

        for (int i = 0; i <= endIdx; i++) {
            for (int j = 0; j < m; j++) {
                auto word = source.substr(i + j * n, n);
                if (wordTimesMap.count(word) > 0 && wordTimesMap[word] > 0) {
                    wordTimesMap[word]--;
                    st.push(word);
                } else {
                    break;
                }
            }
            if (st.size() == m) {
                indexs.emplace_back(i);
            }
            while (!st.empty()) {
                wordTimesMap[st.top()]++;
                st.pop();
            }
        }

        return indexs;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testSubstringWithConcatenationOfAllWords, case1) {
    Solution solution;
    // EXPECT_EQ(
    //     solution.findSubstring("barfoothefoobarman", {"foo", "bar"}),
    //     std::vector<int>({0, 9}));
    // EXPECT_EQ(
    //     solution.findSubstring("wordgoodstudentgoodword", {"word", "student"}),
    //     std::vector<int>({}));
    // EXPECT_EQ(
    //     solution.findSubstring("", {"a"}),
    //     std::vector<int>({}));
    EXPECT_EQ(
        solution.findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "good"}),
        std::vector<int>({8}));
}
