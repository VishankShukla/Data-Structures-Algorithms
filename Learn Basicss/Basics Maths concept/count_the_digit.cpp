#include<bits/stdc++.h>
using namespace std;

// count digit in the nummber 
int count_no(int n){
    int count=0;
    while(n>0){
        count++;
        n=n/10;
    }
    return count;
}

int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    cout<< count_no(n);
    return 0;
}
