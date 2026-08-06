#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<pair<int, int>> players;

        // Store {score, original index}
        for (int i = 0; i < n; i++) {
            players.push_back({score[i], i});
        }

        // Sort in descending order of score
        sort(players.begin(), players.end(), greater<pair<int, int>>());

        vector<string> ans(n);

        for (int rank = 0; rank < n; rank++) {
            int idx = players[rank].second;

            if (rank == 0) {
                ans[idx] = "Gold Medal";
            }
            else if (rank == 1) {
                ans[idx] = "Silver Medal";
            }
            else if (rank == 2) {
                ans[idx] = "Bronze Medal";
            }
            else {
                ans[idx] = to_string(rank + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> score = {10, 3, 8, 9, 4};

    vector<string> result = obj.findRelativeRanks(score);

    cout << "Relative Ranks: ";

    for (string s : result) {
        cout << s << " ";
    }

    return 0;
}