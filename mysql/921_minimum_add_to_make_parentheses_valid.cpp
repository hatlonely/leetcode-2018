#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int minAddToMakeValid(const std::string& str) {
        int i = 0;
        int j = 0;
        for (auto& ch : str) {
            if (ch == '(') {
                i++;
            } else {
                if (i > 0) {
                    i--;
                } else {
                    j++;
                }
            }
        }
        return i + j;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
