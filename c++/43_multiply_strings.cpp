#include <gtest/gtest.h>
#include <iomanip>
#include <sstream>
#include <stack>
#include <string>

class Solution {
   public:
    std::string multiply(std::string num1, std::string num2) {
        int              size1 = (int)num1.size();
        int              size2 = (int)num2.size();
        std::vector<int> vi1(size1);
        std::vector<int> vi2(size2);
        std::vector<int> vi3(size1 + size2, 0);

        for (int i = 0; i < size1; i++) {
            vi1[i] = num1[i] - '0';
        }
        for (int i = 0; i < size2; i++) {
            vi2[i] = num2[i] - '0';
        }

        for (int i = size1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = size2 - 1; j >= 0; j--) {
                int temp       = vi3[i + j + 1] + vi1[i] * vi2[j] + carry;
                vi3[i + j + 1] = temp % 10;
                carry          = temp / 10;
            }
            vi3[i] += carry;
        }

        std::string result;
        int         index = 0;
        while (vi3[index] == 0) {
            index++;
        }
        while (index < vi3.size()) {
            result += '0' + vi3[index++];
        }

        if (result.empty()) {
            return "0";
        }
        return result;
    }
};

const int     kValMaxLen = 9;
const int64_t kValMax    = 1000000000;

class BigInt {
    std::vector<int64_t> values;

   public:
    BigInt(const std::string& str) {
        for (int i = str.size(); i > 0; i -= kValMaxLen) {
            int startIdx = std::max(i - kValMaxLen, 0);
            values.emplace_back(std::stoll(str.substr(startIdx, i - startIdx)));
        }
    }

    std::string to_string() const {
        if (values.empty()) {
            return "0";
        }
        std::stringstream ss;
        ss << values.back();
        for (auto it = values.rbegin() + 1; it != values.rend(); it++) {
            ss << std::setfill('0') << std::setw(kValMaxLen) << *it;
        }
        return ss.str();
    }

    BigInt& addEqual(int64_t num, int shift = 0) {
        if (num == 0) {
            return *this;
        }
        while (shift >= values.size()) {
            values.push_back(0);
        }

        int64_t carry = 0;
        int     idx1  = shift;
        int     len1  = values.size();

        auto val       = values[idx1] + num;
        values[idx1++] = val % kValMax;
        carry          = val / kValMax;
        while (idx1 < len1 && carry != 0) {
            auto val       = values[idx1] + carry;
            values[idx1++] = val % kValMax;
            carry          = val / kValMax;
        }
        if (carry != 0) {
            values.push_back(carry);
        }
        return *this;
    }

    BigInt multiply(const BigInt& bi) const {
        BigInt b("");
        b.values.reserve(bi.values.size() + values.size());
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < bi.values.size(); j++) {
                b.addEqual(values[i] * bi.values[j], i + j);
            }
        }
        return b;
    }

    BigInt operator*(const BigInt& bi) const {
        return multiply(bi);
    }

    BigInt& addEqual(const BigInt& bi, int shift = 0) {
        while (shift > values.size()) {
            values.push_back(0);
        }

        int64_t carry = 0;
        int     idx1  = shift;
        int     idx2  = 0;
        int     len1  = values.size();
        int     len2  = bi.values.size();

        while (idx1 < len1 && idx2 < len2) {
            auto val     = values[idx1] + bi.values[idx2] + carry;
            values[idx1] = val % kValMax;
            carry        = val / kValMax;
            idx1++;
            idx2++;
        }
        while (idx1 < len1) {
            auto val     = values[idx1] + carry;
            values[idx1] = val % kValMax;
            carry        = val / kValMax;
            idx1++;
        }
        while (idx2 < len2) {
            auto val = bi.values[idx2] + carry;
            values.emplace_back(val % kValMax);
            carry = val / kValMax;
            idx2++;
        }
        if (carry != 0) {
            values.emplace_back(carry);
        }

        return *this;
    }

    BigInt& operator+=(const BigInt& bi) {
        return addEqual(bi, 0);
    }

    BigInt operator+(const BigInt& bi) const {
        return BigInt(*this).addEqual(bi);
    }
};

class Solution2 {
   public:
    std::string multiply(const std::string& str1, const std::string& str2) {
        return (BigInt(str1) * BigInt(str2)).to_string();
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.multiply("123", "456"), "56088");
    EXPECT_EQ(solution.multiply("1", "456"), "456");
    EXPECT_EQ(solution.multiply("123456", "23"), "2839488");
    EXPECT_EQ(solution.multiply("9133", "0"), "0");
    EXPECT_EQ(solution.multiply("1200", "62176"), "74611200");
}