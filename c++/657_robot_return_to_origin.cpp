#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    bool judgeCircle(const std::string& moves) {
        int x = 0;
        int y = 0;
        for (auto& ch : moves) {
            switch (ch) {
                case 'R':
                    x += 1;
                    break;
                case 'L':
                    x -= 1;
                    break;
                case 'U':
                    y += 1;
                    break;
                case 'D':
                    y -= 1;
                    break;
            }
        }

        return x == 0 && y == 0;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
