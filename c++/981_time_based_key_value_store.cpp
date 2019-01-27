#include <gtest/gtest.h>
#include <iostream>
#include <set>
#include <unordered_map>

struct TimeValue {
    std::string value;
    int         timestamp;
    bool        operator<(const TimeValue& o) const {
        return timestamp > o.timestamp;
    }
};

// struct CompareTimeValue {
//     bool operator()(const TimeValue& l, const TimeValue& r) {
//         return l.timestamp > r.timestamp;
//     }
// };

class TimeMap {
    std::unordered_map<std::string, std::set<TimeValue>> vals;

   public:
    TimeMap() {
    }

    void set(std::string key, std::string value, int timestamp) {
        if (!vals.count(key)) {
            vals[key] = {{value, timestamp}};
        } else {
            vals[key].insert({value, timestamp});
        }
    }

    std::string get(std::string key, int timestamp) {
        if (!vals.count(key)) {
            return "";
        }
        auto& vs = vals[key];
        auto  it = vs.lower_bound(TimeValue{"", timestamp});
        if (it == vs.end()) {
            return "";
        }
        return it->value;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    auto timeMap = TimeMap();
    timeMap.set("foo", "bar", 1);
    EXPECT_EQ(timeMap.get("foo", 1), "bar");
    EXPECT_EQ(timeMap.get("foo", 3), "bar");
    timeMap.set("foo", "bar2", 4);
    EXPECT_EQ(timeMap.get("foo", 4), "bar2");
    EXPECT_EQ(timeMap.get("foo", 5), "bar2");
    EXPECT_EQ(timeMap.get("foo", 1), "bar");
    EXPECT_EQ(timeMap.get("foo", 3), "bar");
}
