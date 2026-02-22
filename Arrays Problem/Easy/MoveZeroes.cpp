// MoveZeroes.cpp

#include <bits/stdc++.h>
using namespace std;


    void moveZeroes(vector<int>& nums) {
        int j = 0;  // position for next non-zero
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }


int main() {
    
    vector<int> nums = {0, 1, 0, 3, 12};
    
    obj.moveZeroes(nums);
    
    cout << "Output: ";
    for(int num : nums) {
        cout << num << " ";
    }
    
    return 0;
}

// Time Complexity	O(n)
// Space Complexity	O(1)