#include <gtest/gtest.h>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int n, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(n, vector<int>{});
        vector<int>         indegrees(n, 0);
        for (auto p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }

        vector<bool> visited(n, false);
        queue<int>   q;

        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        vector<int> res;
        while (!q.empty()) {
            auto p = q.front();
            res.push_back(p);
            q.pop();
            for (auto ps : edges[p]) {
                if (visited[ps]) {
                    continue;
                }
                indegrees[ps]--;
                if (indegrees[ps] == 0) {
                    q.push(ps);
                    visited[ps] = true;
                }
            }
        }
        if (res.size() != n) {
            return {};
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.findOrder(2, {{1, 0}}), vector<int>({0, 1}));
}