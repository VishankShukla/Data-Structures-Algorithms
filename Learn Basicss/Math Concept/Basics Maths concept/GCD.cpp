#include<bits/stdc++.h>
using namespace std;

// GDC 
void gdc(int n,int m){
int c;
while(n>0 && m>0){
    if(n>m) n=n%m;
    else m=m%n;
}
if(n==0) cout<< m;
else cout<< n;
}
int main(){
    int n1,n2;
    cout <<  "enter the first number:";
    cin >>n1;
    cout <<  "enter the second number:";
    cin >>n2;
    gdc(n1,n2);
    return 0;
}