#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    void allPathsSourceTargetRecursive(
        std::vector<std::vector<int>>& graph,
        std::vector<int>&              path,
        std::vector<std::vector<int>>& result) {
        if (path.back() == graph.size() - 1) {
            result.emplace_back(path);
        }
        for (auto i : graph[path.back()]) {
            path.emplace_back(i);
            allPathsSourceTargetRecursive(graph, path, result);
            path.pop_back();
        }
    }

    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        auto path   = std::vector<int>({0});
        auto result = std::vector<std::vector<int>>();
        allPathsSourceTargetRecursive(graph, path, result);
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
