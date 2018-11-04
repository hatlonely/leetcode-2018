#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

class Solution {
    int                                     n;
    std::map<int, int>                      mi;
    std::uniform_int_distribution<unsigned> dis;
    std::mt19937_64                         mt;

   public:
    Solution(int n, std::vector<int> blacklist) {
        std::sort(blacklist.begin(), blacklist.end());
        auto d = 0;
        for (auto i : blacklist) {
            if (!mi.count(i - d)) {
                mi[i - d] = d;
            }
            d++;
        }
        mi[n] = d;
        std::random_device rd;
        mt  = std::mt19937_64(rd());
        dis = std::uniform_int_distribution<unsigned>(0, n - blacklist.size() - 1);
    }

    int pick() {
        auto r = dis(mt);
        return mi.upper_bound(r)->second + r;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution(20, {4, 6, 7, 9, 10});
    for (int i = 0; i < 20; i++) {
        std::cout << solution.pick() << std::endl;
    }
}