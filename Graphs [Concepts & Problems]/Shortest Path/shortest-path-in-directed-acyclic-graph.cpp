
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void topoSort(int node, vector<int>& visited,
                  stack<int>& st,
                  vector<pair<int,int>> adj[]) {

        visited[node] = 1;

        for (auto it : adj[node]) {
            int v = it.first;

            if (!visited[v]) {
                topoSort(v, visited, st, adj);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {

        vector<pair<int,int>> adj[V];

        // Step 1: Create adjacency list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, visited, st, adj);
            }
        }

        // Step 3: Initialize distance
        vector<int> dis(V, INT_MAX);
        dis[0] = 0;

        // Step 4: Distance Relaxation
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dis[node] == INT_MAX) continue;

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dis[node] + wt < dis[v]) {
                    dis[v] = dis[node] + wt;
                }
            }
        }

        // Step 5: Unreachable nodes = -1
        for (int i = 0; i < V; i++) {
            if (dis[i] == INT_MAX) {
                dis[i] = -1;
            }
        }

        return dis;
    }
};

int main() {

    int V = 10;

    vector<vector<int>> edges = {
        {0, 2, 6},
        {0, 3, 7},
        {0, 4, 9},
        {0, 6, 8},
        {0, 7, 6},
        {1, 2, 6},
        {1, 3, 7},
        {1, 5, 10},
        {1, 6, 1},
        {1, 7, 4},
        {2, 3, 3},
        {2, 6, 10},
        {2, 8, 8},
        {2, 9, 10},
        {3, 5, 3},
        {3, 6, 10},
        {3, 7, 5},
        {5, 6, 9},
        {5, 7, 7},
        {6, 7, 7},
        {6, 8, 8},
        {6, 9, 8},
        {7, 9, 1},
        {8, 9, 6}
    };

    Solution obj;

    vector<int> ans = obj.shortestPath(V, edges);

    cout << "Shortest Distance from Source 0:\n";

    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << ans[i] << endl;
    }

    return 0;
}
