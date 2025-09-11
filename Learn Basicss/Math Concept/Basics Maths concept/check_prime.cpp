#include<bits/stdc++.h>
using namespace std;

// check number is prime or not
void checkprime(int n){
    int k=0;
    for(int i=1;i<n;i++){
        if(n%i==0) k++;
    }
    if(k==1) cout <<"number is prime";
    else cout <<"number is not prime";
}

int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    checkprime(n);
    return 0;
}
