#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int>& arr, int idx) {

        ans.push_back(path);

        for(int i = idx; i < arr.size(); i++) {

            path.push_back(arr[i]);

            solve(arr, i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets are:\n";

    for(auto subset : result) {

        cout << "[";

        for(int i = 0; i < subset.size(); i++) {

            cout << subset[i];

            if(i < subset.size() - 1) {
                cout << ",";
            }
        }

        cout << "]\n";
    }

    return 0;
}