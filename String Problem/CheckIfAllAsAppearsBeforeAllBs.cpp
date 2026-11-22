#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int i = 0;

        while(i < s.size() && s[i] != 'b') {
            i++;
        }

        for(int j = i; j < s.size(); j++) {
            if(s[j] == 'a') return false;
        }

        return true;
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    bool ans = obj.checkString(s);

    if(ans) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
