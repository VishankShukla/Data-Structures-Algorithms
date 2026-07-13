#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //=====================================================
    // Approach 1 : Single Stack (Optimal)
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    //=====================================================

    int largestRectangleArea_Optimal(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxRec = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {

                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxRec = max(maxRec,
                             heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxRec = max(maxRec,
                         heights[element] * (nse - pse - 1));
        }

        return maxRec;
    }

    //=====================================================
    // Approach 2 : Using NSE & PSE Arrays
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    //=====================================================

    vector<int> getNSE(vector<int>& heights, int n) {
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> getPSE(vector<int>& heights, int n) {
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    int largestRectangleArea_NSE(vector<int>& heights) {
        int n = heights.size();

        vector<int> NSE = getNSE(heights, n);
        vector<int> PSE = getPSE(heights, n);

        int maxRec = 0;

        for (int i = 0; i < n; i++) {
            int width = NSE[i] - PSE[i] - 1;
            int area = width * heights[i];
            maxRec = max(maxRec, area);
        }

        return maxRec;
    }
};

int main() {
    Solution obj;

    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << "\n========== Results ==========\n";

    cout << "Approach 1 (Single Stack) : "
         << obj.largestRectangleArea_Optimal(heights) << endl;

    cout << "Approach 2 (NSE + PSE)    : "
         << obj.largestRectangleArea_NSE(heights) << endl;

    return 0;
}