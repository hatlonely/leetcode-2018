#include <gtest/gtest.h>
#include <iostream>
#include <stack>

class MinStack {
    std::stack<int> st;
    std::stack<int> mst;

   public:
    MinStack() {
    }

    void push(int x) {
        if (mst.empty() || mst.top() >= x) {
            mst.push(x);
        }
        st.push(x);
    }

    void pop() {
        if (st.top() == mst.top()) {
            mst.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mst.top();
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    EXPECT_EQ(minStack.getMin(), -3);
    minStack.pop();
    EXPECT_EQ(minStack.top(), 0);
    EXPECT_EQ(minStack.getMin(), -2);
}