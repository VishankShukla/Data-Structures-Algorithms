#include <bits/stdc++.h>
using namespace std;
void LeftRotate(int arr[],int n,int k){
    if(n==0) return;
    if(k>n) {
        cout<<"Rotate Element is more than Element"<<endl;
        return;
    }
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n-k;i++){
        arr[i]=arr[k+i];
    }
    for(int i=0; i<k; i++) {
    arr[n-k+i] = temp[i];
    }

}

void RightRotate(int arr[],int n,int k){
    if(n==0) return;
    if(k>n) {
        cout<<"Rotate Element is more than Element"<<endl;
        return;
    }
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[n-k+i];
    }
    for(int i=n-1;i>=k;i--){
        arr[i]=arr[i-k];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
}


int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout << "Enter the element of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter Your Choice Which side to be rotate \n 1. Left \n 2. Right"<<endl;
    int op;
    cin>>op;
    int k;
    cout<<"How many place you want to rotate ";
    cin>>k;
    if(op==1) LeftRotate(arr,size,k);
    else if(op==2) RightRotate(arr,size,k);
    else cout<<"Wrong Input";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
        
    }

}

