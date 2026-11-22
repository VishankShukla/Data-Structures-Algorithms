#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int n, int curO, int curC,
               vector<string>& ans, string s) {

        if(n == curO && n == curC) {
            ans.push_back(s);
            return;
        }

        if(curO < n) {
            solve(n, curO + 1, curC, ans, s + "(");
        }

        if(curO > curC) {
            solve(n, curO, curC + 1, ans, s + ")");
        }

        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, 1, 0, ans, "(");
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    vector<string> ans = obj.generateParenthesis(n);

    cout << "\nValid Parentheses Combinations:\n";

    for(auto s : ans) {
        cout << s << endl;
    }

    cout << "\nTotal Combinations: " << ans.size() << endl;

    return 0;
}
