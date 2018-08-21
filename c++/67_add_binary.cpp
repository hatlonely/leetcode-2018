#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    std::string addBinary(std::string bin1, std::string bin2) {
        std::reverse(bin1.begin(), bin1.end());
        std::reverse(bin2.begin(), bin2.end());
        int         idx1 = 0;
        int         idx2 = 0;
        int         len1 = bin1.length();
        int         len2 = bin2.length();
        std::string bin3;
        bin3.reserve(std::max(len1, len2) + 1);

        int carry = 0;
        while (idx1 < len1 && idx2 < len2) {
            int sum = bin1[idx1] + bin2[idx2] + carry - '0' * 2;
            bin3.push_back(sum % 2 + '0');
            carry = sum / 2;
            idx1++;
            idx2++;
        }
        while (idx1 < len1) {
            int sum = bin1[idx1] + carry - '0';
            bin3.push_back(sum % 2 + '0');
            carry = sum / 2;
            idx1++;
        }
        while (idx2 < len2) {
            int sum = bin2[idx2] + carry - '0';
            bin3.push_back(sum % 2 + '0');
            carry = sum / 2;
            idx2++;
        }
        if (carry != 0) {
            bin3.push_back(carry + '0');
        }

        std::reverse(bin3.begin(), bin3.end());

        return bin3;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.addBinary("11", "1"), "100");
}