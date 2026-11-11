
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCycleCheck(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 2;

        for (auto it : graph[node]) {
            if (visited[it] == 0) {
                if (dfsCycleCheck(it, graph, visited)) {
                    visited[node] = 3;
                    return true;
                }
            }
            else if (visited[it] == 2) {
                visited[node] = 3;
                return true;
            }
            else if (visited[it] == 3) {
                visited[node] = 3;
                return true;
            }
        }

        visited[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> ans;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            dfsCycleCheck(i, graph, visited);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter adjacency list for each node:\n";

    for (int i = 0; i < n; i++) {
        int m;
        cout << "Number of neighbours of node " << i << ": ";
        cin >> m;

        cout << "Enter neighbours: ";
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    Solution obj;

    vector<int> ans = obj.eventualSafeNodes(graph);

    cout << "Safe Nodes: ";

    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
