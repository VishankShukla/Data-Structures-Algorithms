#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int ans = -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;   // Search left half
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int ans = -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;    // Search right half
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        ans[0] = findFirst(nums, target);
        ans[1] = findLast(nums, target);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = sol.searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]";

    return 0;
}