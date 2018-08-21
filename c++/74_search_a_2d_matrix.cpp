#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        int t = 0;
        int b = m - 1;
        while (t <= b) {
            int x = (t + b) / 2;
            if (matrix[x][0] < target) {
                t = x + 1;
            } else if (matrix[x][0] > target) {
                b = x - 1;
            } else {
                return true;
            }
        }

        if (b < 0) {
            return false;
        }

        int l = 0;
        int r = n;
        while (l <= r) {
            int x = (l + r) / 2;
            if (matrix[b][x] < target) {
                l = x + 1;
            } else if (matrix[b][x] > target) {
                r = x - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.searchMatrix({{1, 3, 5, 7},
                                       {10, 11, 16, 20},
                                       {23, 30, 34, 50}},
                                      50));
}