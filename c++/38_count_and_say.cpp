#include <gtest/gtest.h>
#include <sstream>
#include <string>

class Solution {
   public:
    std::string countAndSay(int n) {
        thread_local std::vector<std::string> vs;
        if (n <= vs.size()) {
            return vs[n - 1];
        }
        if (vs.empty()) {
            vs.emplace_back("1");
        }
        vs.reserve(n);
        for (int i = vs.size() - 1; i < n; i++) {
            const auto&       str = vs[i];
            std::stringstream ss;

            for (int j = 0; j < str.length(); j++) {
                int k = j + 1;
                while (k < str.length() && str[k] == str[j]) {
                    k++;
                }
                ss << k - j << str[j];
                j = k - 1;
            }

            vs.emplace_back(ss.str());
        }

        return vs[n - 1];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.countAndSay(1), "1");
    EXPECT_EQ(solution.countAndSay(2), "11");
    EXPECT_EQ(solution.countAndSay(3), "21");
    EXPECT_EQ(solution.countAndSay(4), "1211");
    EXPECT_EQ(solution.countAndSay(5), "111221");
}