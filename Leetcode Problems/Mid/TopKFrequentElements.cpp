#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hash;
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans;

        // Frequency count
        for (int num : nums) {
            hash[num]++;
        }

        // Min Heap of size k
        for (auto &it : hash) {

            if (pq.size() < k) {
                pq.push({it.second, it.first});
            }
            else {
                if (pq.top().first < it.second) {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }

        // Store answer
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}