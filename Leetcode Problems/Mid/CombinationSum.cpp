#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(candidates, target);

    cout << "Combinations are:\n";
    for (auto &vec : ans) {
        cout << "[ ";
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}