#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int t = x;
    long long r = 0;

    while (t != 0) {
        int d = t % 10;
        r = r * 10 + d;
        t = t / 10;
    }

    return r == x;
}

int main() {
    int x = 121;

    bool result = isPalindrome(x);

    cout << (result ? "true" : "false") << endl;

    return 0;
}