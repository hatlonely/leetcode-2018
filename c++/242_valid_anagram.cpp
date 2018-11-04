#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
   public:
    bool isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) {
            return false;
        }
        auto vc = std::vector<int>(26, 0);
        for (auto ch : s) {
            vc[ch - 'a'] += 1;
        }
        for (auto ch : t) {
            if (vc[ch - 'a'] == 0) {
                return false;
            }
            vc[ch - 'a'] -= 1;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isAnagram("anagram", "nagaram"));
    EXPECT_FALSE(solution.isAnagram("rat", "cat"));
}