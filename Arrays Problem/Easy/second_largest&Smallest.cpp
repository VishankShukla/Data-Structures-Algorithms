#include <bits/stdc++.h>
using namespace std;

int SecondLargest(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    return slargest;
}

int SecondSmallest(int arr[],int n){
    int smallest=arr[0];
    int s_smallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            s_smallest=smallest;
            smallest=arr[i];
        }else if(arr[i]>smallest && arr[i]<s_smallest){
            s_smallest=arr[i];
        }
    }
    return s_smallest;
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
    int secondlarge = SecondLargest(arr,size);
    int secondsmall = SecondSmallest(arr,size); 
    cout <<"Second Largest: "<< secondlarge<<endl;
    cout <<"Second Smallest: "<< secondsmall<<endl;
   
}