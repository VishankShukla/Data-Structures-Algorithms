#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int sorted = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            sorted++;
        }
    }

    return sorted <= 1;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};

    bool result = check(nums);

    cout << (result ? "true" : "false") << endl;

    return 0;
}