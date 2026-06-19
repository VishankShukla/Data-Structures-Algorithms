#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
unordered_map<int, int> mp;
mp[0] = 1;

    int sum = 0, ans = 0;

    for (int x : nums) {
        sum += x;

        if (mp.count(sum - k))
            ans += mp[sum - k];

        mp[sum]++;
    }

    return ans;
}

};

int main() {
int n, k;

cout << "Enter size of array: ";
cin >> n;

vector<int> nums(n);

cout << "Enter array elements: ";
for (int i = 0; i < n; i++) {
    cin >> nums[i];
}

cout << "Enter value of k: ";
cin >> k;

Solution obj;
int result = obj.subarraySum(nums, k);

cout << "Number of subarrays with sum " << k << " = " << result << endl;

return 0;

}
