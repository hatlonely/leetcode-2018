#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>

class Solution2 {
   public:
    int subarraysDivByK(const std::vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum % k == 0) {
                    count += 1;
                }
            }
        }
        return count;
    }
};

class Solution {
   public:
    int subarraysDivByK(const std::vector<int>& nums, int k) {
        std::vector<int>             sums(nums.size(), 0);
        int                          sum = 0;
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto m = sum % k;
            if (m < 0) {
                m = k + m;
            }
            if (map.count(m)) {
                map[m] += 1;
            } else {
                map[m] = 1;
            }
        }

        int count = 0;
        for (auto p : map) {
            if (p.first == 0) {
                count += p.second;
            }
            if (p.second >= 2) {
                auto n = p.second;
                count += n * (n - 1) / 2;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.subarraysDivByK({4, 5, 0, -2, -3, 1}, 5), 7);
    EXPECT_EQ(solution.subarraysDivByK({-1, 2, 9}, 2), 2);
}
