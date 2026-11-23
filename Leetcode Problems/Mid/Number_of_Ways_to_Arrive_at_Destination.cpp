#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < roads.size(); i++) {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    int src = 0;
    int target = n - 1;

    vector<long long> dis(n, LLONG_MAX);
    vector<int> ways(n, 0);

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    pq.push({0, src});
    dis[src] = 0;
    ways[src] = 1;

    int mod = 1e9 + 7;

    while(!pq.empty()) {

        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if(d > dis[node]) continue;

        for(auto it : adj[node]) {

            int v = it.first;
            long long wt = it.second;

            if(dis[v] > wt + d) {

                dis[v] = wt + d;
                ways[v] = ways[node];

                pq.push({dis[v], v});

            }
            else if(dis[v] == wt + d) {

                ways[v] = (ways[v] + ways[node]) % mod;
            }
        }
    }

    return ways[target];
}

int main() {

    int n, m;
    cout << "Enter number of nodes and roads: ";
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(3));

    cout << "Enter roads (u v time):\n";

    for(int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    cout << "Number of shortest paths: "
         << countPaths(n, roads) << endl;

    return 0;
}
