#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> ans;
    string mp[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(string digits, int i, string temp) {
        if (i == digits.size()) {
            ans.push_back(temp);
            return;
        }

        for (char ch : mp[digits[i] - '2']) {
            temp.push_back(ch);
            solve(digits, i + 1, temp);
            temp.pop_back();   // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string temp = "";
        solve(digits, 0, temp);

        return ans;
    }
};

int main() {
    Solution obj;

    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);

    cout << "Letter Combinations:\n";
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}