#include<bits/stdc++.h>
using namespace std;

// Function to rotate the array
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;   // Handle k > n

    // Reverse whole array
    reverse(nums.begin(), nums.end());

    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse remaining elements
    reverse(nums.begin() + k, nums.end());
}

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter rotation steps (k): ";
    cin >> k;

    rotateArray(nums, k);

    cout << "Rotated array: ";
    for(int num : nums) {
        cout << num << " ";
    }

    return 0;
}