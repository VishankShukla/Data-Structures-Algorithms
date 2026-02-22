#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

bool check(vector<int>& nums) {
    int sorted = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++){
        if(nums[i] > nums[(i+1) % n]){
            sorted++;
        }
    }
    return sorted <= 1;
}

int main()
{
    int n;
    cout << "Size Of the array :";
    cin >> n;   // size input

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i] ;   // elements input
    }

    if(check(nums)) {
        cout << Sorted";
    } else {
        cout << "Not Sorted";
    }

    return 0;
}