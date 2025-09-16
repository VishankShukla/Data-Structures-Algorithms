#include <bits/stdc++.h>
using namespace std;


void InsertionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        int j =i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
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
    InsertionSort(arr, size);
    for(auto it: arr){
        cout<<it<<" ";
    }
}