#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int low, int mid , int high){
    vector<int> temp;
    int i=low;
    int j= mid+1;
    
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int ind=low; ind<=high;ind++){
        arr[ind]=temp[ind-low];
    }
    
}

void MergeSort(int arr[],int low,int high){
    int mid = (low+high)/2;
    if(low>=high) return;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
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
    MergeSort(arr, 0,size-1);
    cout<<"Sorted Array : ";
    for(auto it: arr){
        cout<<it<<" ";
    }
}

// Time Complexity: O(n log n) (dividing the array and merging)
// Space Complexity: O(n) (for the temporary array temp)