#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const string& sr = strs[0];

        for (int i = 0; i < sr.size(); i++) {
            for (const string& strCheck : strs) {
                if (i >= strCheck.size() || sr[i] != strCheck[i]) {
                    return sr.substr(0, i);
                }
            }
        }
        return sr;
    }
};

int main() {
    Solution obj;

    vector<string> strs;
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    string result = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}