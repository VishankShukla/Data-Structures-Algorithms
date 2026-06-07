#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n) {
    unordered_set<int> seen;

    while (n != 1) {
        if (seen.count(n))
            return false;

        seen.insert(n);

        int r = 0;

        while (n != 0) {
            int d = n % 10;
            r += d * d;
            n /= 10;
        }

        n = r;
    }

    return true;
}

int main() {
    int n = 19;

    bool result = isHappy(n);

    cout << (result ? "true" : "false") << endl;

    return 0;
}