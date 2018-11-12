#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class Iterator {
    struct Data;
    Data* data;

   public:
    Iterator(const std::vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    int  next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int  num;
    bool b;

   public:
    PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
        b = Iterator::hasNext();
        if (b) {
            num = Iterator::next();
        }
    }

    int peek() {
        return num;
    }

    int next() {
        int val = num;
        if (Iterator::hasNext()) {
            num = Iterator::next();
        } else {
            b = false;
        }
        return val;
    }

    bool hasNext() const {
        return b;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}