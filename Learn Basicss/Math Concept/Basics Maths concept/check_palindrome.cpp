#include<bits/stdc++.h>
using namespace std;

// check palindrome  or not
void palindromee(int n){
    int k = n;
    int rev = 0;
    while(k>0){
        int ld = k%10;
        rev = rev*10 + ld;
        k =k/10;
    }
    if(rev == n){
        cout << "yes";
    }
    else{ 
        cout << "no";
        
    }
}

int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    palindromee(n);
    return 0;
}
