#include <bits/stdc++.h>
using namespace std;

int Parition(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high){
            i++;
        }
        while(arr[j]>=arr[pivot] && j>=low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(vector<int> &arr,int low,int high){
    if(i<j){
        int pivot = Parition(arr,low,high);
        QuickSort(arr,low,pivot-1);
        QuickSort(arr,pivot+1,high);
    }
    
}
int main()
{
    cout<<"Enter The Size Of The Element: ";
    int size,n;
    cin>>size;
    vector<int> arr;
    cout<<"Enetr Array Element: ";
    for(int i=0;i<size;i++){
        cin>>n;
        arr.push_back(n);
    }
    QuickSort(arr,0,size-1);
    cout<<"Sorted : ";
    for(auto it: arr){
        cout<<it<<" ";
    }
}