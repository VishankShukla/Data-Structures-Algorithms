#include <bits/sdtc++.h>
using namespace std;

class MinStack {
public:
    long long mini = INT_MAX;
    stack<long long> st;

    MinStack() {
    }

    void push(int value) {
        if (st.empty()) {
            mini = value;
            st.push(value);
        }
        else if (value >= mini) {
            st.push(value);
        }
        else {
            st.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2LL * mini - x;
        }

        if (st.empty())
            mini = INT_MAX;
    }

    int top() {
        long long x = st.top();

        if (x < mini)
            return mini;

        return x;
    }

    int getMin() {
        return mini;
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Minimum: " << minStack.getMin() << endl;

    minStack.pop();

    cout << "Top: " << minStack.top() << endl;
    cout << "Minimum: " << minStack.getMin() << endl;

    return 0;
}