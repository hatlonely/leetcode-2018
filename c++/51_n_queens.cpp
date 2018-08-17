#include <gtest/gtest.h>
#include <bitset>
#include <string>
#include <vector>

class Solution {
   public:
    void solveNQueensRecursive(
        std::vector<std::vector<std::string>>& queens,
        std::vector<std::string>&              strs,
        std::vector<int>&                      nums,
        std::vector<int>&                      choose,
        std::vector<bool>&                     diagonal1,
        std::vector<bool>&                     diagonal2,
        int                                    n) {
        if (nums.size() == n) {
            std::vector<std::string> queen(n);
            for (int i = 0; i < n; i++) {
                queen[i] = strs[nums[i]];
            }
            queens.emplace_back(queen);
            return;
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
            diagonal1[i + nums.size()]     = true;
            diagonal2[i + n - nums.size()] = true;
            choose[i]                      = true;
            nums.push_back(i);
            solveNQueensRecursive(queens, strs, nums, choose, diagonal1, diagonal2, n);
            nums.pop_back();
            choose[i]                      = false;
            diagonal1[i + nums.size()]     = false;
            diagonal2[i + n - nums.size()] = false;
        }
    }
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> queens;
        std::vector<std::string>              strs;
        std::vector<int>                      nums;
        for (int i = 0; i < n; i++) {
            std::string str(n, '.');
            str[i] = 'Q';
            strs.emplace_back(std::move(str));
        }

        std::vector<std::string> queen(n);
        std::vector<bool>        diagonal1(2 * n, false);
        std::vector<bool>        diagonal2(2 * n, false);
        std::vector<int>         choose(n);

        solveNQueensRecursive(queens, strs, nums, choose, diagonal1, diagonal2, n);

        return queens;
    }
};

class Solution1 {
   public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> queens;
        std::vector<std::string>              strs;
        std::vector<int>                      nums;
        int                                   size = 1;
        for (int i = 0; i < n; i++) {
            std::string str(n, '.');
            str[i] = 'Q';
            strs.emplace_back(std::move(str));
            nums.emplace_back(i);
            size *= (i + 1);
        }

        for (int i = 0; i < size; i++) {
            std::vector<std::string> queen(n);
            std::vector<bool>        diagonal1(2 * n, false);
            std::vector<bool>        diagonal2(2 * n, false);
            std::next_permutation(nums.begin(), nums.end());
            bool isMatch = true;
            for (int i = 0; i < n; i++) {
                if (diagonal1[i + nums[i]]) {
                    isMatch = false;
                    break;
                }
                diagonal1[i + nums[i]] = true;
                if (diagonal2[i + n - nums[i]]) {
                    isMatch = false;
                    break;
                }
                diagonal2[i + n - nums[i]] = true;
            }
            if (!isMatch) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                queen[i] = strs[nums[i]];
            }
            queens.emplace_back(queen);
        }
        return queens;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.solveNQueens(4),
        std::vector<std::vector<std::string>>(
            {{".Q..",
              "...Q",
              "Q...",
              "..Q."},
             {"..Q.",
              "Q...",
              "...Q",
              ".Q.."}}));
}