#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    bool canFinish(int n, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(n, vector<int>{});
        vector<int>         indegrees(n, 0);
        for (auto prerequisite : prerequisites) {
            edges[prerequisite[1]].emplace_back(prerequisite[0]);
            indegrees[prerequisite[0]]++;
        }

        queue<int>  qi;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                qi.push(i);
                visited[i] = true;
            }
        }

        while (!qi.empty()) {
            int q = qi.front();
            qi.pop();

            for (auto v : edges[q]) {
                if (visited[v]) {
                    continue;
                }
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    qi.push(v);
                    visited[v] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

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