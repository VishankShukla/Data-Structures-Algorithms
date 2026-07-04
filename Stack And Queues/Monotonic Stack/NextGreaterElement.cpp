#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = mp[nums1[i]];
        }

        return nums1;
    }
};

int main() {
    int n1, n2;

    cout << "Enter size of nums1: ";
    cin >> n1;

    vector<int> nums1(n1);
    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of nums2: ";
    cin >> n2;

    vector<int> nums2(n2);
    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    Solution obj;
    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "Answer: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}