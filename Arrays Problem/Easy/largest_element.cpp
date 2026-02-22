#include <bits/stdc++.h>
using namespace std;

int LargestElement(int arr[],int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(largest < arr[i]) largest=arr[i];
    }
    return largest;
}

int main()
{
    cout<<"Enter The Size Of The Array: ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enetr Array Element: ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    int Largest = LargestElement(arr,size);
    cout << "Largest Element: " <<Largest;
}

// Time Complexity: O(N), where N is the size of the array, as we are iterating through the array once.
// Space Complexity: O(1), as we are using a constant