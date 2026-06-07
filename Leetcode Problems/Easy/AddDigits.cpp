#include <bits/stdc++.h>
using namespace std;

int addDigits(int num) {
    while (num >= 10) {
        int n = 0;

        while (num != 0) {
            int d = num % 10;
            n = n + d;
            num = num / 10;
        }

        num = n;
    }

    return num;
}

int main() {
    int num = 38;

    int result = addDigits(num);

    cout << result << endl;

    return 0;
}