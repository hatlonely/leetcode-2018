#include <gtest/gtest.h>
#include <iostream>

class Solution {
    std::vector<std::pair<int, int>> vp = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    bool isRobotBounded(std::string instructions) {
        auto p = std::pair<int, int>(0, 0);
        int  i = 0;

        for (int j = 0; j < 4; j++) {
            for (auto ch : instructions) {
                if (ch == 'R') {
                    i++;
                    i %= 4;
                } else if (ch == 'L') {
                    i--;
                    if (i < 0) {
                        i += 4;
                    }
                } else {
                    p.first += vp[i].first;
                    p.second += vp[i].second;
                }
            }
            if (p.first == 0 && p.second == 0) {
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

TEST(test, case0) {
    Solution solution;
    EXPECT_TRUE(solution.isRobotBounded("GGLLGG"));
    EXPECT_TRUE(solution.isRobotBounded("GL"));
    EXPECT_FALSE(solution.isRobotBounded("GG"));
}
