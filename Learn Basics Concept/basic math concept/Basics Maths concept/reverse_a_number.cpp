#include<bits/stdc++.h>
using namespace std;

// reverse a number
int reverse(int n){
    int rev=0;
    while(n>0){
        int ld = n%10;
        rev = rev*10+ld;
        n=n/10;
    }
    return rev;
}

int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    cout << reverse(n);
    return 0;
}
