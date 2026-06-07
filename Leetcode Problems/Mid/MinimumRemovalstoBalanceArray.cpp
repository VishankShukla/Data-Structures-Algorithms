#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = n;
    int i = 0;

    for (int j = 0; j < n; j++) {

        while (nums[j] > (long long)nums[i] * k) {
            i++;
        }

        int windowSize = j - i + 1;
        ans = min(ans, n - windowSize);
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 3, 10, 7, 5};
    int k = 2;

    int result = minRemoval(nums, k);

    cout << result << endl;

    return 0;
}