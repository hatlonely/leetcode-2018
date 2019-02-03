#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    std::vector<int> sumEvenAfterQueries(
        std::vector<int>& arr, const std::vector<std::vector<int>>& queries) {
        std::vector<int> result;

        int sum = 0;
        for (const auto& i : arr) {
            if (i % 2 == 0) {
                sum += i;
            }
        }

        for (const auto& query : queries) {
            const int val = query[0];
            const int idx = query[1];
            if (arr[idx] % 2 == 0) {
                sum -= arr[idx];
            }
            arr[idx] += val;
            if (arr[idx] % 2 == 0) {
                sum += arr[idx];
            }
            result.push_back(sum);
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
    auto     arr = std::vector<int>({1, 2, 3, 4});
    EXPECT_EQ(solution.sumEvenAfterQueries(arr, {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}}), std::vector<int>({8, 6, 2, 4}));
}