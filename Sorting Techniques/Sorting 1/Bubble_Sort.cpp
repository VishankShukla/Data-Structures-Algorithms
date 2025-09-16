#include <bits/stdc++.h>
using namespace std;


void BubbleSort(int n[],int size){
    for(int i=0;i<size;i++){
        int noswap =0;
        for(int j=0;j<size-i-1;j++){
            if(n[j]>n[j+1]){
                swap(n[j],n[j+1]);
                // swap work as
                // int temp = n[j];
                // n[j] = n[i];
                // n[i]=temp;
                noswap=1;
            }
            
        }
        if (noswap==0) break;
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
    BubbleSort(arr, size);
    for(auto it: arr){
        cout<<it<<" ";
    }
}