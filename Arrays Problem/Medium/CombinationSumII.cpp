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

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = obj.combinationSum2(candidates, target);

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