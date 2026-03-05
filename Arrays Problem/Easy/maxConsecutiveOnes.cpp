#include <bits/stdc++.h>
using namespace std;

int Maxcount(vector<int> nums) {  
    int n = nums.size();
    int cnt = 0, maxCount = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == 1) {
            cnt++;
        } else {
            maxCount = max(cnt, maxCount);
            cnt = 0;
        }
    }

    maxCount = max(cnt, maxCount);
    return maxCount;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    int result = Maxcount(nums);  
    cout << result;
}