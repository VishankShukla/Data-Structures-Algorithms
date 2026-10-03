#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {

        // Last index par pahunch gaye
        if (i >= nums.size() - 1)
            return true;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        int j = 1;

        while (j <= nums[i]) {

            if (solve(nums, i + j, dp)) {
                dp[i] = 1;
                return true;
            }

            j++;
        }

        dp[i] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, dp);
    }
};

int main() {

    Solution solution;

    vector<int> nums = {2, 3, 1, 1, 4};

    bool ans = solution.canJump(nums);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}