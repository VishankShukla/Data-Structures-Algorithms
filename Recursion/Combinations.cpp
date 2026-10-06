#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int n, int k,
               vector<vector<int>>& ans,
               vector<int>& temp) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int start = i; start <= n; start++) {
            temp.push_back(start);

            solve(start + 1, n, k, ans, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, n, k, ans, temp);

        return ans;
    }
};

int main() {
    Solution obj;

    int n = 4;
    int k = 2;

    vector<vector<int>> ans = obj.combine(n, k);

    for (auto &v : ans) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}