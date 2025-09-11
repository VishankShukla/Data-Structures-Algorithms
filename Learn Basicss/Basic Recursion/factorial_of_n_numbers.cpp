#include <bits/stdc++.h>
using namespace std;

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
   return num * factorial(num-1);
}

int main() {
    int num;
    cout << "Enter The Number: ";
    cin >> num;
    
    cout << "Sum is: " << factorial(num) << endl;
    return 0;
}