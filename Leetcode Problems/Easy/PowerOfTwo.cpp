#include <bits/stdc++.h>
using namespace std;

// ==================== RECURSION ====================

class SolutionRecursion {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1)
            return true;

        if (n <= 0 || n % 2 != 0)
            return false;

        return isPowerOfTwo(n / 2);
    }
};


// ==================== BITWISE ====================

class SolutionBitwise {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};


// ==================== MAIN ====================

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    SolutionRecursion recursion;
    SolutionBitwise bitwise;

    cout << "\nRecursion: ";

    if (recursion.isPowerOfTwo(n))
        cout << "true";
    else
        cout << "false";

    cout << "\nBitwise: ";

    if (bitwise.isPowerOfTwo(n))
        cout << "true";
    else
        cout << "false";

    cout << endl;

    return 0;
}