#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }

        return pq.top();
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Kth Largest Element = " << obj.findKthLargest(nums, k) << endl;

    return 0;
}