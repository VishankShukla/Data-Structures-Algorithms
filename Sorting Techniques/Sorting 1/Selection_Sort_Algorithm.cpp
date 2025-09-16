#include <bits/stdc++.h>
using namespace std;


void SelectionSort(int n[],int size){
    for(int i=0;i<=size-2;i++){
        for(int j=i+1;j<=size-1;j++){
            if(n[j]<n[i]){
                swap(n[j],n[i]);
                // swap work as
                // int temp = n[j];
                // n[j] = n[i];
                // n[i]=temp;
            }
            
        }
    } 
}



int main()
{
    cout<<"Enter The Size Of The Array: ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enetr Array Element: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    SelectionSort(arr, size);
    for(auto it: arr){
        cout<<it<<" ";
    }
}