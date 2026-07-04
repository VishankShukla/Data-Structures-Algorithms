#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 2*n - 1; i >= 0; i--) {
            int idx = i % n;

            while(!st.empty() && nums[idx] >= st.top()) {
                st.pop();
            }

            if(i < n) {
                ans[idx] = st.empty() ? -1 : st.top();
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}