#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int  n        = barcodes.size();
        int  maxtimes = 0;
        int  m        = 0;
        auto times    = unordered_map<int, int>();
        for (auto i : barcodes) {
            if (times.count(i) == 0) {
                times[i] = 0;
            }
            times[i]++;
            if (times[i] > maxtimes) {
                maxtimes = times[i];
                m        = i;
            }
        }

        int i = 0;
        for (; maxtimes > 0; maxtimes--) {
            barcodes[i * 2] = m;
            i++;
        }
        times.erase(m);
        for (auto p : times) {
            for (int j = 0; j < p.second; j++) {
                if (i * 2 < n) {
                    barcodes[i * 2] = p.first;
                } else {
                    if (n % 2 != 0) {
                        barcodes[i * 2 - n] = p.first;
                    } else {
                        barcodes[i * 2 - (n - 1)] = p.first;
                    }
                }
                i++;
            }
        }
        return barcodes;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution    solution;
    vector<int> barcodes = {2, 2, 2, 1, 5};
    solution.rearrangeBarcodes(barcodes);
    EXPECT_EQ(barcodes, std::vector<int>({2, 5, 2, 1, 2}));
}