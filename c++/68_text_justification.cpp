#include <gtest/gtest.h>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> fullJustify(const std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> lines;
        for (int i = 0; i < words.size();) {
            int l   = i;
            int r   = i + 1;
            int len = words[i].length();
            while (r < words.size()) {
                if (len + words[r].length() + 1 > maxWidth) {
                    break;
                }
                len += words[r].length() + 1;
                r++;
            }
            auto line          = std::string(maxWidth, ' ');
            int  idx           = 0;
            int  totalSpaceNum = r - l - 1 + maxWidth - len;
            int  currentNum    = r - l - 1;
            for (int q = 0; q < words[l].length(); q++) {
                line[idx++] = words[l][q];
            }
            for (int p = l + 1; p < r; p++) {
                if (r != words.size()) {
                    int currentSpaceNum = (totalSpaceNum + currentNum - 1) / currentNum;
                    for (int q = 0; q < currentSpaceNum; q++) {
                        line[idx++] = ' ';
                    }
                    currentNum--;
                    totalSpaceNum -= currentSpaceNum;
                } else {
                    line[idx++] = ' ';
                }
                for (int q = 0; q < words[p].length(); q++) {
                    line[idx++] = words[p][q];
                }
            }
            lines.emplace_back(std::move(line));
            i = r;
        }

        return lines;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testTextJustification, case1) {
    Solution solution;
    EXPECT_EQ(solution.fullJustify(
                  {"Science", "is", "what", "we", "understand",
                   "well", "enough", "to", "explain",
                   "to", "a", "computer.", "Art", "is",
                   "everything", "else", "we", "do"},
                  20),
              std::vector<std::string>(
                  {"Science  is  what we",
                   "understand      well",
                   "enough to explain to",
                   "a  computer.  Art is",
                   "everything  else  we",
                   "do                  "}));
}

TEST(testTextJustification, case2) {
    Solution solution;
    EXPECT_EQ(solution.fullJustify(
                  {"What", "must", "be", "acknowledgment", "shall", "be"},
                  16),
              std::vector<std::string>(
                  {"What   must   be", "acknowledgment  ", "shall be        "}));
}
