#include<bits/stdc++.h>
using namespace std;
int i=1;
void print(int n){
    if(i<=n){
        cout << i << endl ;
        i++;
        print(n);
    }
}

int main(){
    int n;
    cout<< "Enter the number = ";
    cin>>n;
    print(n);
}