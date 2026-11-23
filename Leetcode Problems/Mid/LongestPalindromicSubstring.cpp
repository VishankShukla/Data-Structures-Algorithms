#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string oddLength(int i, string& s) {

        int left = i - 1;
        int right = i + 1;

        while(left >= 0 && right < s.size() &&
              s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string evenLength(int i, string& s) {

        int left = i;
        int right = i + 1;

        while(left >= 0 && right < s.size() &&
              s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

public:
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            string odd = oddLength(i, s);
            if(odd.size() > ans.size())
                ans = odd;

            string even = evenLength(i, s);
            if(even.size() > ans.size())
                ans = even;
        }

        return ans;
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    string ans = obj.longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << ans << endl;

    return 0;
}
