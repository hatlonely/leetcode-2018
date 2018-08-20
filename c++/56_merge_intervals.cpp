#include <gtest/gtest.h>
#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator==(const Interval& l, const Interval& r) {
    return l.start == r.start && l.end == r.end;
}

std::ostream& operator<<(std::ostream& oss, const Interval& interval) {
    oss << "(" << interval.start << ", " << interval.end << ")";
    return oss;
}

class Solution {
    struct IntervalCompare {
        bool operator()(const Interval& l, const Interval& r) const {
            return l.start < r.start;
        }
    };

   public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), IntervalCompare());
        int idx = 1;
        int n   = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[idx - 1].end >= intervals[i].start) {
                intervals[idx - 1].end = std::max(intervals[idx - 1].end, intervals[i].end);
            } else {
                intervals[idx++] = intervals[i];
            }
        }
        for (int i = idx; i < n; i++) {
            intervals.pop_back();
        }
        return intervals;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMergeIntervals, case1) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    auto     mergedIntervals = std::vector<Interval>({{1, 6}, {8, 10}, {15, 18}});
    EXPECT_EQ(solution.merge(intervals), mergedIntervals);
}

TEST(testMergeIntervals, case2) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 3}});
    auto     mergedIntervals = std::vector<Interval>({{1, 3}});
    EXPECT_EQ(solution.merge(intervals), mergedIntervals);
}

TEST(testMergeIntervals, case3) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 4}, {0, 2}, {3, 5}});
    auto     mergedIntervals = std::vector<Interval>({{0, 5}});
    EXPECT_EQ(solution.merge(intervals), mergedIntervals);
}