#include <gtest/gtest.h>
#include <stack>
#include <vector>

class Solution {
   public:
    int largestRectangleArea(std::vector<int>& heights) {
        int             maxArea = 0;
        std::stack<int> st;
        heights.emplace_back(0);
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
};

class SolutionNSquare {
   public:
    int largestRectangleArea(const std::vector<int>& heights) {
        int length  = heights.size();
        int maxArea = 0;
        for (int i = 0; i < length; i++) {
            int j = i + 1;
            for (; j < length; j++) {
                if (heights[i] > heights[j]) {
                    break;
                }
            }
            int k = i - 1;
            for (; k >= 0; k--) {
                if (heights[i] > heights[k]) {
                    break;
                }
            }
            maxArea = std::max(maxArea, (j - k - 1) * heights[i]);
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
    auto     heights = std::vector<int>({2, 1, 5, 6, 2, 3});
    EXPECT_EQ(solution.largestRectangleArea(heights), 10);
}

TEST(test, case2) {
    Solution solution;
    auto     heights = std::vector<int>({2, 1, 2});
    EXPECT_EQ(solution.largestRectangleArea(heights), 3);
}
