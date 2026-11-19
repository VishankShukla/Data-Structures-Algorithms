
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        bool added = false;

        for(int i = 0; i < n; i++) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            }
            else if(intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            else {
                result.push_back(newInterval);
                added = true;
                result.insert(result.end(), intervals.begin()+i, intervals.end());
                break;
            }
        }

        if(!added) {
            result.push_back(newInterval);
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 2}, {3, 5}, {6, 7}, {8, 10}
    };

    vector<int> newInterval = {4, 9};

    vector<vector<int>> ans = obj.insert(intervals, newInterval);

    cout << "Merged Intervals: ";

    for(auto &v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    cout << endl;

    return 0;
}
