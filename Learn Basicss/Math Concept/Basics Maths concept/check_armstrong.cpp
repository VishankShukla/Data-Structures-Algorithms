#include<bits/stdc++.h>
using namespace std;

// check number is armstrong or not
void armstrong(int n){
    int k=n;
    int count =  log10(n)+1;
    int num = 0;
    while(n>0){
        int ld =n%10;
        num=num + pow(ld,count);
        n=n/10;
    }
    if(k==num) cout<<"yes";
    else cout<<"no";
}

int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    armstrong(n);
    return 0;
}
