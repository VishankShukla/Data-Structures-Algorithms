#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;

        // Check for overflow
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return 0;

        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return 0;

        rev = rev * 10 + digit;
        x = x / 10;
    }

    return rev;
}

int main() {
    int x = 123;

    int result = reverseNumber(x);

    cout << result << endl;

    return 0;
}