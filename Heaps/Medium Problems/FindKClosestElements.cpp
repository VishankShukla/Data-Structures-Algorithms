#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;

        while (r - l + 1 > k) {
            if (x - arr[l] <= arr[r] - x)
                r--;
            else
                l++;
        }

        vector<int> ans;
        for (int i = l; i <= r; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k, x;
    cin >> k >> x;

    Solution obj;
    vector<int> ans = obj.findClosestElements(arr, k, x);

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}