#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);
        queue<int> que;

        for(int i = 0; i < n; i++) {

            if(colored[i] != -1) continue;

            que.push(i);
            colored[i] = 0;

            while(!que.empty()) {
                int node = que.front();
                int color = colored[node];
                que.pop();

                for(auto it : graph[node]) {
                    if(colored[it] == -1) {
                        colored[it] = 1 - color;
                        que.push(it);
                    }
                    else if(colored[it] == color) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(obj.isBipartite(graph)) {
        cout << "Bipartite Graph";
    }
    else {
        cout << "Not a Bipartite Graph";
    }

    return 0;
}
