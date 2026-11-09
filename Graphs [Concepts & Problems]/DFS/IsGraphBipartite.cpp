#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int i, int color, vector<vector<int>>& graph, vector<int>& colored) {
        colored[i] = color;

        for(auto it : graph[i]) {
            if(colored[it] == -1) {
                if(!dfs(it, 1 - colored[i], graph, colored)) {
                    return false;
                }
            }
            else if(colored[it] == colored[i]) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);

        for(int i = 0; i < n; i++) {
            if(colored[i] == -1) {
                if(!dfs(i, 0, graph, colored)) {
                    return false;
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
