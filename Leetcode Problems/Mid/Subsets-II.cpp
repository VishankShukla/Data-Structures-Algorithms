#include <bits/stdc++.h>
using namespace std;

// 90. Subsets II
class Solution {
public:
    void findSubset(int idx, vector<int> ds, vector<int>& nums,
                    vector<vector<int>>& ans) {

        ans.push_back(ds);

        int n = nums.size();

        for (int i = idx; i < n; i++) {

            // Same level par duplicate element skip karo
            if (i != idx && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);

            findSubset(i + 1, ds, nums, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;

        // Duplicates ko identify karne ke liye sort
        sort(nums.begin(), nums.end());

        findSubset(0, ds, nums, ans);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    cout << "All Unique Subsets:\n";

    for (auto subset : ans) {
        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}