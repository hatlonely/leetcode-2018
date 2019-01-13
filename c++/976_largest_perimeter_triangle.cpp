#include <gtest/gtest.h>
#include <iostream>

class Solution {
   public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 2; i < nums.size(); i++) {
            auto a = nums[i - 2];
            auto b = nums[i - 1];
            auto c = nums[i];
            if (b + c > a) {
                return a + b + c;
            }
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    auto     nums = std::vector<int>({3, 6, 2, 3});
    EXPECT_EQ(solution.largestPerimeter(nums), 8);
}

TEST(test, case2) {
    Solution solution;
    auto     nums = std::vector<int>({1, 2, 1});
    EXPECT_EQ(solution.largestPerimeter(nums), 0);
}

TEST(test, case3) {
    Solution solution;
    auto     nums = std::vector<int>({2, 1, 2});
    EXPECT_EQ(solution.largestPerimeter(nums), 5);
}

TEST(test, case4) {
    Solution solution;
    auto     nums = std::vector<int>({3, 2, 3, 4});
    EXPECT_EQ(solution.largestPerimeter(nums), 10);
}
