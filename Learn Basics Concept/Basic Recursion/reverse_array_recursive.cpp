#include<bits/stdc++.h>
using namespace std;
int  arrreverse(int i,int j, int a[]){
    if(i>j){
        return 0;
    }
    int temp =a[i];
    a[i]=a[j];
    a[j]=temp;
    return arrreverse(i+1,j-1,a);
}
int  main(){
    int a[]={1,2,3,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    arrreverse(0,size-1,a);
    for(int i=0;i<size;i++){
        cout << a[i] << "\t";
    }
}