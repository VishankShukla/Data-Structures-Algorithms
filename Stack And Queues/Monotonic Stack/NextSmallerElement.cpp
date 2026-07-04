#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        vector<int> ans(n, -1);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 4};
    Solution sol;

    vector<int> ans = sol.nextSmallerElement(arr);


    cout << "The next smaller elements are: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}