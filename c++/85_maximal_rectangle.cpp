#include <gtest/gtest.h>
#include <stack>
#include <vector>

class Solution {
   public:
    int largestRectangleArea(const std::vector<int> heights) {
        std::stack<int> st;
        int             maxArea = 0;
        for (int i = 0; i < heights.size();) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int height = heights[st.top()];
                st.pop();
                int length = st.empty() ? i : i - st.top() - 1;
                maxArea    = std::max(maxArea, height * length);
            }
        }
        return maxArea;
    }

    int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int  maxArea = 0;
        int  m       = matrix.size();
        int  n       = matrix[0].size();
        auto hss     = std::vector<std::vector<int>>(m, std::vector<int>(n + 1, 0));
        for (int j = 0; j < n; j++) {
            hss[0][j] = matrix[0][j] == '1' ? 1 : 0;
            maxArea   = largestRectangleArea(hss[0]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hss[i][j] = matrix[i][j] == '1' ? hss[i - 1][j] + 1 : 0;
            }
            maxArea = std::max(maxArea, largestRectangleArea(hss[i]));
        }

        return maxArea;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.largestRectangleArea({3, 1, 3, 2, 2, 0}), 6);
    EXPECT_EQ(solution.largestRectangleArea({1, 0}), 1);
    EXPECT_EQ(solution.maximalRectangle({
                  {'1', '0', '1', '0', '0'},
                  {'1', '0', '1', '1', '1'},
                  {'1', '1', '1', '1', '1'},
                  {'1', '0', '0', '1', '0'},
              }),
              6);
}