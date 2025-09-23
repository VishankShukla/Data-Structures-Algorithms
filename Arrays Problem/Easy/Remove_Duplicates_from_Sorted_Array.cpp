#include <bits/stdc++.h>
using namespace std;
int RemoveDuplicate(int arr[],int size){
    int i=0;
    for(int j=1;j<size;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
            
        }
    }
    return i+1;
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
    int n=RemoveDuplicate(arr,size);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

   
   
}