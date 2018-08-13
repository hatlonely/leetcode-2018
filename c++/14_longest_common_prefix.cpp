#include <gtest/gtest.h>
#include <string>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }
        const std::string& str = strs[0];
        for (size_t i = 0; i < str.length(); i++) {
            const auto& c = str[i];
            for (size_t j = 1; j < strs.size(); j++) {
                if (c != strs[j][i]) {
                    return str.substr(0, i);
                }
            }
        }

        return str;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testLongestCommonPrefix, case1) {
    Solution solution;
    EXPECT_EQ(solution.longestCommonPrefix({"flower", "flow", "flight"}), "fl");
}