#include <iostream>
using namespace std;

int recursiveSum(int num, int fn) {
    if (fn <= num) {
        return fn + recursiveSum(num, fn + 1);
    } else {
        return 0;
    }
}

int main() {
    int num;
    cout << "Enter The Number: ";
    cin >> num;
    
    cout << "Sum is: " << recursiveSum(num, 1) << endl;
    return 0;
}
