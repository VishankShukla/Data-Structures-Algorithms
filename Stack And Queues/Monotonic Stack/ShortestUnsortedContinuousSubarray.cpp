#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();
        stack<int> st;

        int left = n;
        int right = 0;

        // Find left boundary
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                left = min(left, st.top());
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Find right boundary
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                right = max(right, st.top());
                st.pop();
            }
            st.push(i);
        }

        if (right <= left)
            return 0;

        return right - left + 1;
    }
};

int main() {

    // Test Case 1
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

    Solution obj;

    int ans = obj.findUnsortedSubarray(nums);

    cout << "Length of shortest unsorted subarray = " << ans << endl;

    return 0;
}