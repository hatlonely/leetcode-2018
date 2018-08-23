#include <gtest/gtest.h>
#include <vector>

class Solution {
   public:
    void combineRecursive(int i, int n, int k,
                          std::vector<int>&              nums,
                          std::vector<std::vector<int>>& combinations) {
        if (k == 0) {
            combinations.emplace_back(nums);
            return;
        }
        for (; i <= n; i++) {
            nums.push_back(i);
            combineRecursive(i + 1, n, k - 1, nums, combinations);
            nums.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        if (n < k) {
            return {};
        }
        std::vector<int>              nums;
        std::vector<std::vector<int>> combinations;
        combineRecursive(1, n, k, nums, combinations);
        return combinations;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(
        solution.combine(4, 2),
        std::vector<std::vector<int>>({
            {1, 2},
            {1, 3},
            {1, 4},
            {2, 3},
            {2, 4},
            {3, 4},
        }));
}