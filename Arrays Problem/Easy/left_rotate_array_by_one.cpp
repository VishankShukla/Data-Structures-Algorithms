#include <bits/stdc++.h>
using namespace std;
void LeftRotate(int arr[],int size){
    int temp = arr[0];
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=temp;
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
    LeftRotate(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}

// Complexity Analysis

// Time Complexity: O(n), as we iterate through the array only once.

// Space Complexity: O(1) as no extra space is used