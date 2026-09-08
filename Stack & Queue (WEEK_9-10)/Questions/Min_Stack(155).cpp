#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long mini = LLONG_MAX;

public:
    MinStack() {
    }

    void push(int value) {
        long long val = value;

        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            // Encode the new minimum
            st.push(2 * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long x = st.top();
        st.pop();

        // x is an encoded value
        if (x < mini) {
            mini = 2 * mini - x;
        }

        if (st.empty()) {
            mini = LLONG_MAX;
        }
    }

    int top() {
        if (st.empty())
            return -1;

        long long x = st.top();

        // Encoded value means actual top is mini
        if (x < mini)
            return (int)mini;

        return (int)x;
    }

    int getMin() {
        if (st.empty())
            return -1;

        return (int)mini;
    }
};
