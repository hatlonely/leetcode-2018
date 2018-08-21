#include <gtest/gtest.h>
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
    std::vector<Interval> insert(std::vector<Interval>& intervals, const Interval& interval) {
        int l = 0;
        int r = intervals.size() - 1;
        while (l <= r) {
            auto m = (l + r) / 2;
            if (interval.start > intervals[m].start) {
                l = m + 1;
            } else if (interval.start < intervals[m].start) {
                r = m - 1;
            } else {
                l = m;
                break;
            }
        }

        int n = intervals.size();
        if (l > 0 && interval.start <= intervals[l - 1].end) {
            intervals[l - 1].end = std::max(interval.end, intervals[l - 1].end);
        } else if (l < n && interval.end >= intervals[l].start) {
            intervals[l].start = std::min(interval.start, intervals[l].start);
            intervals[l].end   = std::max(interval.end, intervals[l].end);
        } else {
            intervals.insert(intervals.begin() + l, interval);
            return intervals;
        }

        int idx = std::max(l - 1, 0);
        for (int i = idx + 1; i < n; i++) {
            if (intervals[idx].end >= intervals[i].start) {
                intervals[idx].end = std::max(intervals[idx].end, intervals[i].end);
            } else {
                intervals[++idx] = intervals[i];
            }
        }
        for (int i = idx + 1; i < n; i++) {
            intervals.pop_back();
        }

        return intervals;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testInsertInterval, case1) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 3}, {6, 9}});
    auto     insertIntervals = std::vector<Interval>({{1, 5}, {6, 9}});
    EXPECT_EQ(solution.insert(intervals, {2, 5}), insertIntervals);
}

TEST(testInsertInterval, case2) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({});
    auto     insertIntervals = std::vector<Interval>({{5, 7}});
    EXPECT_EQ(solution.insert(intervals, {5, 7}), insertIntervals);
}

TEST(testInsertInterval, case3) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}});
    auto     insertIntervals = std::vector<Interval>({{1, 2}, {3, 10}, {12, 16}});
    EXPECT_EQ(solution.insert(intervals, {4, 8}), insertIntervals);
}

TEST(testInsertInterval, case4) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 5}});
    auto     insertIntervals = std::vector<Interval>({{1, 5}});
    EXPECT_EQ(solution.insert(intervals, {2, 3}), insertIntervals);
}

TEST(testInsertInterval, case5) {
    Solution solution;
    auto     intervals       = std::vector<Interval>({{1, 5}});
    auto     insertIntervals = std::vector<Interval>({{1, 7}});
    EXPECT_EQ(solution.insert(intervals, {5, 7}), insertIntervals);
}
