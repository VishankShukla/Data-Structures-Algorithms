#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty()) {
                ans.push_back(intervals[i]);
            }
            else if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = obj.merge(intervals);

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}