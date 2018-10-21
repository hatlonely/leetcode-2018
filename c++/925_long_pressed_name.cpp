#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "treelinknode.hpp"

class Solution {
   public:
    bool isLongPressedName(const std::string& name, const std::string& typed) {
        if (name.empty()) {
            return typed.empty();
        }

        if (name[0] != typed[0]) {
            return false;
        }

        int i = 1;
        for (int j = 1; j < typed.length(); j++) {
            if (i > name.length()) {
                return false;
            }
            if (name[i] != typed[j]) {
                if (typed[j] != typed[j - 1]) {
                    return false;
                }
            } else {
                i++;
            }
        }

        return i == name.length();
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.isLongPressedName("alex", "aaleex"));
    EXPECT_TRUE(solution.isLongPressedName("alex", "aaleex"));
    EXPECT_FALSE(solution.isLongPressedName("pyplrz", "ppyypllr"));
    EXPECT_FALSE(solution.isLongPressedName("alex", "aaleexxb"));
}
