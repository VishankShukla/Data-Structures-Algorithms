#include <iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    if (n == 0) return 1;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number of digits: " << countDigits(num) << endl;
    return 0;
}