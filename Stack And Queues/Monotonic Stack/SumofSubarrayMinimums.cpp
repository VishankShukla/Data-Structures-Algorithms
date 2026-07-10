#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        const int M = 1e9 + 7;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long total = 1LL * arr[i] * ls * rs;

            sum = (sum + total) % M;
        }

        return sum;
    }

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return result;
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Sum of Subarray Minimums = "
         << obj.sumSubarrayMins(arr) << endl;

    return 0;
}