#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

const std::unordered_map<char, std::string> kDigitKeysMap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

class Solution {
   public:
    void letterCombinationsRecursive(std::vector<std::string>& combinations, const std::string& digits) {
        if (digits.empty()) {
            return;
        }
        const auto& keys = kDigitKeysMap.at(digits[0]);
        auto        n    = combinations.size();
        for (size_t i = 1; i < keys.size(); i++) {
            for (size_t j = 0; j < n; j++) {
                combinations.emplace_back(combinations[j]);
            }
        }
        for (size_t i = 0; i < keys.size(); i++) {
            for (size_t j = 0; j < n; j++) {
                combinations[i * n + j].push_back(keys[i]);
            }
        }

        return letterCombinationsRecursive(combinations, digits.substr(1));
    }

    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (digits.empty()) {
            return std::vector<std::string>();
        }

        std::vector<std::string> combinations;
        size_t                   len = 1;
        combinations.reserve(len);
        for (const auto& ch : digits) {
            len *= kDigitKeysMap.at(digits[0]).length();
        }
        std::string str;
        str.reserve(digits.size());
        combinations.emplace_back(str);
        letterCombinationsRecursive(combinations, digits);
        return combinations;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testLetterCombinationsOfAPhoneNumber, case1) {
    Solution solution;
    auto     combinations = solution.letterCombinations("23");
    EXPECT_EQ(std::unordered_set<std::string>(combinations.begin(), combinations.end()), std::unordered_set<std::string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
}

TEST(testLetterCombinationsOfAPhoneNumber, case2) {
    Solution solution;
    auto     combinations = solution.letterCombinations("");
    EXPECT_EQ(std::unordered_set<std::string>(combinations.begin(), combinations.end()), std::unordered_set<std::string>({}));
}
