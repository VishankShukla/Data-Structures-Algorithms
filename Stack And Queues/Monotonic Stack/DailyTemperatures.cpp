#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();

                ans[idx] = i - idx;
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution obj;
    vector<int> ans = obj.dailyTemperatures(temperatures);

    cout << "Answer: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}