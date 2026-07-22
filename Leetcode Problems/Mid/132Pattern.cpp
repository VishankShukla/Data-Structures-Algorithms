#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        int third = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {

            if (nums[i] < third)
                return true;

            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 1, 4, 2};

    if (obj.find132pattern(nums))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}