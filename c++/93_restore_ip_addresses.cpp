#include <gtest/gtest.h>
#include <iostream>

class Solution {
    bool validAddress(const std::string &str) {
        if (str.empty()) {
            return false;
        }
        if (str[0] == '0') {
            return str.length() == 1;
        }
        if (str.length() > 3) {
            return false;
        }
        if (str.length() < 3) {
            return true;
        }

        return (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0') <= 255;
    }

   public:
    std::vector<std::string> restoreIpAddresses(const std::string &str) {
        std::vector<std::string> ips;

        for (int i1 = 1; i1 < 4 && i1 < str.length() - 2; i1++) {
            auto s1 = str.substr(0, i1);
            if (!validAddress(s1)) {
                break;
            }
            for (int i2 = i1 + 1; i2 - i1 < 4 && i2 < str.length() - 1; i2++) {
                auto s2 = str.substr(i1, i2 - i1);
                if (!validAddress(s2)) {
                    break;
                }
                for (int i3 = i2 + 1; i3 - i2 < 4 && i3 < str.length(); i3++) {
                    auto s3 = str.substr(i2, i3 - i2);
                    if (!validAddress(s3)) {
                        break;
                    }
                    auto s4 = str.substr(i3);
                    if (!validAddress(s4)) {
                        continue;
                    }
                    ips.emplace_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }

        return ips;
    }
};

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.restoreIpAddresses("25525511135"), std::vector<std::string>({"255.255.11.135", "255.255.111.35"}));
    EXPECT_EQ(solution.restoreIpAddresses("0000"), std::vector<std::string>({"0.0.0.0"}));
    EXPECT_EQ(solution.restoreIpAddresses("010010"), std::vector<std::string>({"0.10.0.10", "0.100.1.0"}));
}
