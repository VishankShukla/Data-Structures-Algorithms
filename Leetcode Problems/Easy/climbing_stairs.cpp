#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int recursion(int n) {
    if (n == 0 || n == 1)
        return 1;

    return recursion(n - 1) + recursion(n - 2);
}

// 2. Memoization (Top-Down DP)
int memoization(int n, vector<int>& dp) {
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = memoization(n - 1, dp)
                 + memoization(n - 2, dp);
}

// 3. Tabulation (Bottom-Up DP)
int tabulation(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 4. Space Optimized DP
int spaceOptimized(int n) {
    int lastprev = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int next = lastprev + prev;

        lastprev = prev;
        prev = next;
    }

    return prev;
}

// Main Function
int main() {

    int n;

    cout << "Enter number of stairs: ";
    cin >> n;

    // 1. Recursion
    cout << "\n1. Recursion: ";
    cout << recursion(n) << endl;

    // 2. Memoization
    vector<int> dp(n + 1, -1);

    cout << "2. Memoization: ";
    cout << memoization(n, dp) << endl;

    // 3. Tabulation
    cout << "3. Tabulation: ";
    cout << tabulation(n) << endl;

    // 4. Space Optimized
    cout << "4. Space Optimized: ";
    cout << spaceOptimized(n) << endl;

    return 0;
}