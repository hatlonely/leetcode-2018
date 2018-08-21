#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    int minDistance(const std::string& word1, const std::string& word2) {
        int  m         = word1.length();
        int  n         = word2.length();
        auto distances = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }

        distances[0][0] = word1[0] != word2[0];
        for (int j = 1; j < n; j++) {
            if (word1[0] != word2[j]) {
                distances[0][j] = distances[0][j - 1] + 1;
            } else {
                distances[0][j] = j;
            }
        }

        for (int i = 1; i < m; i++) {
            if (word1[i] != word2[0]) {
                distances[i][0] = distances[i - 1][0] + 1;
            } else {
                distances[i][0] = i;
            }
            for (int j = 1; j < n; j++) {
                distances[i][j] = std::min({
                    distances[i - 1][j - 1] + (word1[i] != word2[j]),
                    distances[i - 1][j] + 1,
                    distances[i][j - 1] + 1,
                });
            }
        }
        return distances[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.minDistance("horse", "ros"), 3);
    EXPECT_EQ(solution.minDistance("intention", "execution"), 5);
    EXPECT_EQ(solution.minDistance("sea", "eat"), 2);
    EXPECT_EQ(solution.minDistance("dinitrophenylhydrazine", "acetylphenylhydrazine"), 6);
}