#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s="asdfghzxcvbn";
    int numRows=3;
    if (numRows == 1)
        cout<<s;
    string str;
    int n = s.size();
    for (int i = 0; i < numRows; i++)
    {
        int idx = i;
        int down = 2 * (numRows - 1 - i);
        int up = i * 2;
        bool goDown = true;
        while (idx < n)
        {
            str += s[idx];
            if (i == 0)
            {
                idx += down;
            }
            else if (i == numRows - 1)
            {
                idx += up;
            }
            else
            {
                if (goDown)
                {
                    idx += down;
                }
                else
                {
                    idx += up;
                }
                goDown = !goDown;
            }
        }
    }
cout<<str;
return 0;
}