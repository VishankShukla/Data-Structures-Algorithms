#include<bits/stdc++.h>
using namespace std;

// print all divisors
void printdivisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    printdivisor(n);
    return 0;
}
