#include <gtest/gtest.h>
#include <iostream>
#include <set>

struct compare_t {
    bool operator()(const std::vector<int>* vi1, const std::vector<int>* vi2) {
        auto v1 = (*vi1)[0] * (*vi1)[0] + (*vi1)[1] * (*vi1)[1];
        auto v2 = (*vi2)[0] * (*vi2)[0] + (*vi2)[1] * (*vi2)[1];
        return v1 < v2;
    }
};

class Solution {
   public:
    std::vector<std::vector<int>> kClosest(const std::vector<std::vector<int>>& points, int k) {
        std::set<const std::vector<int>*, compare_t> vs;
        for (const auto& point : points) {
            vs.insert(&point);
            if (vs.size() > k) {
                vs.erase(std::prev(vs.end()));
            }
        }
        std::vector<std::vector<int>> result;
        for (const auto point : vs) {
            result.push_back(*point);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.kClosest({{3, 3}, {5, -1}, {-2, 4}}, 2),
              std::vector<std::vector<int>>({{3, 3}, {-2, 4}}));
}
