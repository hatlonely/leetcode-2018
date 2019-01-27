#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    std::string strWithout3a3b(int numa, int numb) {
        int         n = numa + numb;
        std::string str(n, '0');

        if (numa > numb) {
            for (int i = 0; i < n;) {
                if (numb == 0) {
                    while (i < n) {
                        str[i++] = 'a';
                    }
                } else if (numa > numb) {
                    str[i++] = 'a';
                    str[i++] = 'a';
                    str[i++] = 'b';
                    numa -= 2;
                    numb -= 1;
                } else {
                    str[i++] = 'a';
                    str[i++] = 'b';
                    numa -= 1;
                    numb -= 1;
                }
            }
        } else {
            for (int i = 0; i < n;) {
                if (numa == 0) {
                    while (i < n) {
                        str[i++] = 'b';
                    }
                } else if (numb > numa) {
                    str[i++] = 'b';
                    str[i++] = 'b';
                    str[i++] = 'a';
                    numb -= 2;
                    numa -= 1;
                } else {
                    str[i++] = 'b';
                    str[i++] = 'a';
                    numb -= 1;
                    numa -= 1;
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

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.strWithout3a3b(1, 2), "bba");
    EXPECT_EQ(solution.strWithout3a3b(4, 1), "aabaa");
    EXPECT_EQ(solution.strWithout3a3b(4, 8), "bbabbabbabba");
    EXPECT_EQ(solution.strWithout3a3b(2, 5), "bbabbab");
    EXPECT_EQ(solution.strWithout3a3b(84, 41), "aabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaa");
}