#include<bits/stdc++.h>
using namespace std;

bool CheckSorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
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
    bool isSorted= CheckSorted(arr,size);
    if(isSorted) cout<< "Array is Sorted";
    else cout<< "Array is Not Sorted";
   
}