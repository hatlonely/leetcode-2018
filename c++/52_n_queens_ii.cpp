#include <gtest/gtest.h>

class Solution {
   public:
    void totalNQueensRecursive(
        int&               total,
        int                n,
        std::vector<int>&  nums,
        std::vector<bool>& choose,
        std::vector<bool>& diagonal1,
        std::vector<bool>& diagonal2) {
        if (n == nums.size()) {
            total++;
        }
        for (int i = 0; i < n; i++) {
            if (choose[i]) {
                continue;
            }
            if (diagonal1[i + nums.size()]) {
                continue;
            }
            if (diagonal2[i + n - nums.size()]) {
                continue;
            }
            choose[i]                      = true;
            diagonal1[i + nums.size()]     = true;
            diagonal2[i + n - nums.size()] = true;
            nums.push_back(i);
            totalNQueensRecursive(total, n, nums, choose, diagonal1, diagonal2);
            nums.pop_back();
            choose[i]                      = false;
            diagonal1[i + nums.size()]     = false;
            diagonal2[i + n - nums.size()] = false;
        }
    }
    int totalNQueens(int n) {
        std::vector<int>  nums;
        std::vector<bool> choose(n, false);
        std::vector<bool> diagonal1(2 * n, false);
        std::vector<bool> diagonal2(2 * n, false);
        int               total = 0;
        totalNQueensRecursive(total, n, nums, choose, diagonal1, diagonal2);
        return total;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.totalNQueens(4), 2);
}
