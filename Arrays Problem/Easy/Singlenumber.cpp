#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int xorr =0;
        for(int i=0;i<nums.size();i++){
            xorr = xorr^nums[i];

        }
        return xorr;
    }

int main() {
    vector<int> nums = {1,1,3,4,5,6,4,6,5};
    int result = singleNumber(nums);  
    cout << result;
}