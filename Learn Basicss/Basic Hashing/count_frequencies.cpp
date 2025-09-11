#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter The Size Of Array : ";
    cin>>n;
    int a[n];
    cout << "Enter The Array Element under 1 to 12 : ";
    int hash[13]={0};
    for(int i=0;i<n;i++){
        cin >> a[i];
        hash[a[i]]++;
    }
    
    while(true){
        int q;
        cout<< "Enter The Number Find Number Of Occurrenc : ";
        cin>>q;
        cout << hash[q]<<endl<<"Press 1 to search another element";
        int k;
        cin>>k;
        if(k!=1) break;
    }
    
    return 0;
}

