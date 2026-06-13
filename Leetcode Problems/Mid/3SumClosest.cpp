#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int curr_sum = nums[i] + nums[l] + nums[r];

            if (abs(curr_sum - target) < abs(closestSum - target)) {
                closestSum = curr_sum;
            }

            if (curr_sum < target) {
                l++;
            } 
            else if (curr_sum > target) {
                r--;
            } 
            else {
                cout << target << endl;
                return 0;   // exact match found
            }
        }
    }

    cout << closestSum << endl;

    return 0;
}