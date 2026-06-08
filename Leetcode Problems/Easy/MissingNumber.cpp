#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;

        for (int i = 0; i < n; i++) {
            result = result ^ i ^ nums[i];
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 0, 1}; // test case
    cout << obj.missingNumber(nums) << endl;

    return 0;
}