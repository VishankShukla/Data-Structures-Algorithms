#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int count = 0;

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    int ans = obj.lengthOfLastWord(s);

    cout << "Length of last word = " << ans << endl;

    return 0;
}