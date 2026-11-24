#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count(int src, int max, vector<vector<pair<int,int>>>& adj) {
        int n = adj.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dis(n, INT_MAX);

        pq.push({0, src});
        dis[src] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (dis[node] < d || max < d) continue;

            for (auto it : adj[node]) {
                if (dis[it.first] > it.second + d) {
                    dis[it.first] = it.second + d;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        int c = 0;

        for (int i = 0; i < n; i++) {
            if (src != i && dis[i] <= max) {
                c++;
            }
        }

        return c;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        int mini = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int c = count(i, distanceThreshold, adj);

            if (mini >= c) {
                mini = c;
                ans = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int distanceThreshold = 4;

    int ans = obj.findTheCity(n, edges, distanceThreshold);

    cout << "City with smallest number of neighbors: " << ans << endl;

    return 0;
}
