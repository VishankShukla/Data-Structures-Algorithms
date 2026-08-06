// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> ans;

        // {sum, {i, j}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        int n = nums1.size();
        int m = nums2.size();

        // Heap me har row ka first pair dalo
        for (int i = 0; i < min(n, k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- && !pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int i = curr.second.first;
            int j = curr.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // Same row ka next pair push karo
            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};

int main() {

    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution obj;
    vector<vector<int>> ans = obj.kSmallestPairs(nums1, nums2, k);

    cout << "K Smallest Pairs:\n";
    for (auto &pair : ans) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    return 0;
}