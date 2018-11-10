#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

const auto dict = std::vector<std::string>({
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
});

class Solution {
   public:
    int uniqueMorseRepresentations(const std::vector<std::string>& words) {
        std::unordered_set<std::string> uws;
        for (const auto& word : words) {
            std::string str;
            for (const auto& ch : word) {
                str += dict[ch - 'a'];
            }
            uws.insert(str);
        }

        return uws.size();
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}