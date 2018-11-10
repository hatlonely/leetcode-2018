#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

const auto keyboard = std::unordered_map<char, int>({
    {'q', 1},
    {'w', 1},
    {'e', 1},
    {'r', 1},
    {'t', 1},
    {'y', 1},
    {'u', 1},
    {'i', 1},
    {'o', 1},
    {'p', 1},
    {'a', 2},
    {'s', 2},
    {'d', 2},
    {'f', 2},
    {'g', 2},
    {'h', 2},
    {'j', 2},
    {'k', 2},
    {'l', 2},
    {'z', 3},
    {'x', 3},
    {'c', 3},
    {'v', 3},
    {'b', 3},
    {'n', 3},
    {'m', 3},
});

class Solution {
   public:
    std::vector<std::string> findWords(const std::vector<std::string>& words) {
        std::vector<std::string> vs;
        for (auto& word : words) {
            int  l           = keyboard.at(std::tolower(word[0]));
            bool isSameLevel = true;
            for (int i = 1; i < word.length(); i++) {
                if (keyboard.at(std::tolower(word[i])) != l) {
                    isSameLevel = false;
                    break;
                }
            }
            if (isSameLevel) {
                vs.emplace_back(word);
            }
        }
        return vs;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.findWords({"Hello", "Alaska", "Dad", "Peace"}), std::vector<std::string>({"Alaska", "Dad"}));
}
