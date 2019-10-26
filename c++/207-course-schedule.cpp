#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    bool canFinish(int n, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(n, vector<int>{});
        for (auto prerequisite : prerequisites) {
            edges[prerequisite[0]].emplace_back(prerequisite[1]);
        }

        for (int i = 0; i < n; i++) {
            auto visited = vector<bool>(n, false);
            if (!travel(edges, visited, i)) {
                return false;
            }
        }

        return true;
    }

    bool travel(const vector<vector<int>>& edges, vector<bool>& visited, int i) {
        if (visited[i]) {
            return false;
        }

        visited[i] = true;
        for (auto j : edges[i]) {
            if (!travel(edges, visited, j)) {
                return false;
            }
        }
        visited[i] = false;

        return true;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_TRUE(solution.canFinish(2, {{1, 0}}));
    EXPECT_FALSE(solution.canFinish(2, {{1, 0}, {0, 1}}));
}