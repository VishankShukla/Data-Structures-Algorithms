#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if(m.find(comp) != m.end()) return {m[comp],i};
        m[nums[i]]=i;
    }
    return {};
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result =twoSum(nums,target);
    cout << result[0] << " "<< result[1];
}