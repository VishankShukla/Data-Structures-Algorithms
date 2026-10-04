#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string& text1, string& text2,
              vector<vector<int>>& dp) {

        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
            return dp[i][j];
        }

        int option1 = solve(i + 1, j, text1, text2, dp);
        int option2 = solve(i, j + 1, text1, text2, dp);

        dp[i][j] = max(option1, option2);

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, text1, text2, dp);
    }
};

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    Solution obj;

    int answer = obj.longestCommonSubsequence(text1, text2);

    cout << "Longest Common Subsequence length: " << answer << endl;

    return 0;
}