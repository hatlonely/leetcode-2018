#include <gtest/gtest.h>
#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>>             anagrams;
        std::unordered_map<std::string, std::vector<int>> strSets;
        for (int i = 0; i < strs.size(); i++) {
            auto str = strs[i];
            std::sort(str.begin(), str.end());
            if (strSets.count(str) == 0) {
                strSets[str] = std::vector<int>();
            }
            strSets[str].emplace_back(i);
        }
        for (const auto& kv : strSets) {
            std::vector<std::string> anagram;
            anagram.reserve(kv.second.size());
            for (const auto& i : kv.second) {
                anagram.emplace_back(strs[i]);
            }
            anagrams.emplace_back(std::move(anagram));
        }
        return anagrams;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}),
        std::vector<std::vector<std::string>>({{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}));
}