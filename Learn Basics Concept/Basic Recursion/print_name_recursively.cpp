#include<bits/stdc++.h>
using namespace std;
void print(int n,int i,string a){
    if(i<=n){
        cout << a << endl ;
        print(n,i+1,a);
    }
}

int main(){
    int n;
    string a ;
    cout << "Enter the name;"<<endl;
    cin>>a;
    cout<< "Enter the number times print = ";
    cin>>n;
    print(n,1,a);
}