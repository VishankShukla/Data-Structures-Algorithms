
#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    int dx[] = {-1,0,0,1};
    int dy[] = {0,-1,1,0};

    pq.push({0,{0,0}});
    dis[0][0] = 0;

    while(!pq.empty()) {
        int effort = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if(dis[r][c] < effort) continue;

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m) {

                int diff = max(effort, abs(heights[r][c] - heights[nr][nc]));

                if(diff < dis[nr][nc]) {
                    pq.push({diff,{nr,nc}});
                    dis[nr][nc] = diff;
                }
            }
        }
    }

    return dis[n-1][m-1];
}

int main() {
    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    cout << "Minimum Effort: " << minimumEffortPath(heights) << endl;

    return 0;
}
