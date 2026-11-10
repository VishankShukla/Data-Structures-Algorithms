
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj,
                  vector<int>& visited, vector<int>& ans) {

        visited[node] = 2;

        for (auto it : adj[node]) {

            if (visited[it] == 0) {
                if (dfsCheck(it, adj, visited, ans)) {
                    return true;
                }
            }
            else if (visited[it] == 2) {
                return true;
            }
        }

        visited[node] = 1;
        ans.push_back(node);

        return false;
    }

public:
    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> visited(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {

            if (visited[i] == 0) {
                if (dfsCheck(i, adj, visited, ans) == true) {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution obj;

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> ans = obj.findOrder(numCourses, prerequisites);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}
