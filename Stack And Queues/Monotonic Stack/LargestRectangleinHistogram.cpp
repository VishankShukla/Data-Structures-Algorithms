#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        if (n == 0) return 0;

        int maxRec = 0;

        vector<int> NSE = getNSE(heights, n);
        vector<int> PSE = getPSE(heights, n);

        cout << "Index\tHeight\tPSE\tNSE\tWidth\tArea\n";

        for (int i = 0; i < n; i++) {
            int width = NSE[i] - PSE[i] - 1;
            int area = width * heights[i];

            cout << i << "\t"
                 << heights[i] << "\t"
                 << PSE[i] << "\t"
                 << NSE[i] << "\t"
                 << width << "\t"
                 << area << endl;

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

    cout << "Enter heights:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << "\nLargest Rectangle Area = "
         << obj.largestRectangleArea(heights)
         << endl;

    return 0;
}