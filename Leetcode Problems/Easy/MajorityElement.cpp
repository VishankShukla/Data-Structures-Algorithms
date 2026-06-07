#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();

    int element;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            element = nums[i];
        }

        if (nums[i] == element) {
            count++;
        } else {
            count--;
        }
    }

    return element;
}

int main() {
    vector<int> nums = {6, 5, 5};  // yaha input change kar sakte ho

    int ans = majorityElement(nums);

    cout << "Majority Element: " << ans << endl;

    return 0;
}