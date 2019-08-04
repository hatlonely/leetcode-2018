#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class SnapshotArray {
    std::vector<std::map<int, int>> elements;
    int                             snapTimes = 0;

   public:
    SnapshotArray(int length) {
        elements = std::vector<std::map<int, int>>(length);
        for (int i = 0; i < elements.size(); i++) {
            elements[i]    = std::map<int, int>();
            elements[i][0] = 0;
        }
    }

    void set(int i, int val) {
        elements[i][snapTimes] = val;
    }

    int snap() {
        return snapTimes++;
    }

    int get(int i, int snapID) {
        if (snapID > elements[i].rbegin()->first) {
            return elements[i].rbegin()->second;
        }

        auto it = elements[i].lower_bound(snapID);
        if (it->first != snapID) {
            --it;
        }
        return it->second;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// TEST(test, case1) {
//     SnapshotArray* obj = new SnapshotArray(3);
//     obj->set(0, 5);
//     EXPECT_EQ(obj->get(0, 0), 5);
//     EXPECT_EQ(obj->snap(), 0);
//     EXPECT_EQ(obj->snap(), 1);
//     obj->set(0, 6);
//     EXPECT_EQ(obj->get(0, 0), 5);
//     EXPECT_EQ(obj->get(0, 1), 5);
//     EXPECT_EQ(obj->get(0, 2), 6);
// }

TEST(test, case2) {
    //     ["SnapshotArray","set","snap","set","snap","set","snap","set","get","get","snap"]
    // [[4],[1,5],[],[0,16],[],[2,15],[],[2,5],[1,0],[0,2],[]]
    // [null,null,0,null,1,null,2,null,5,16,3]

    SnapshotArray* obj = new SnapshotArray(4);
    obj->set(1, 5);
    EXPECT_EQ(obj->snap(), 0);
    obj->set(0, 16);
    EXPECT_EQ(obj->snap(), 1);
    obj->set(2, 15);
    EXPECT_EQ(obj->snap(), 2);
    obj->set(2, 5);
    EXPECT_EQ(obj->get(1, 0), 5);
    EXPECT_EQ(obj->get(0, 1), 16);
    EXPECT_EQ(obj->get(0, 2), 16);
    EXPECT_EQ(obj->snap(), 3);
}