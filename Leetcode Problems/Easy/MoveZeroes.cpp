#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0; // position for next non-zero

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums={0,9,3,0,2};
    moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    return 0;
}