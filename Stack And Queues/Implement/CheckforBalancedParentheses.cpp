#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char it : s) {
            if (it == '(' || it == '{' || it == '[') {
                st.push(it);
            } 
            else {
                if (st.empty())
                    return false;

                char ch = st.top();
                st.pop();

                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{')) {
                    continue;
                } 
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter brackets: ";
    cin >> s;

    if (obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}