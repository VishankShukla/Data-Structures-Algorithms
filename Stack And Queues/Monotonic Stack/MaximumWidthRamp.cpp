#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int widthRamp = 0;
        stack<int> st;

        // Store indices with decreasing values
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                widthRamp = max(widthRamp, i - st.top());
                st.pop();
            }
            if (st.empty())
                break;
        }

        return widthRamp;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {6, 0, 8, 2, 1, 5};

    cout << "Maximum Width Ramp = " << obj.maxWidthRamp(nums) << endl;

    return 0;
}