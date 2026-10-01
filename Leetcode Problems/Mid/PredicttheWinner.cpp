#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
    if (l == r)
        return nums[l];

    if (dp[l][r] != -1)
        return dp[l][r];

    int firstElement = nums[l] - solve(nums, l + 1, r, dp);
    int lastElement = nums[r] - solve(nums, l, r - 1, dp);

    dp[l][r] = max(firstElement, lastElement);

    return dp[l][r];
}

bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(nums, 0, n - 1, dp) >= 0;
}

int main() {
    vector<int> nums = {1, 5, 2};

    bool result = predictTheWinner(nums);

    if (result)
        cout << "Player 1 can win" << endl;
    else
        cout << "Player 1 cannot win" << endl;

    return 0;
}