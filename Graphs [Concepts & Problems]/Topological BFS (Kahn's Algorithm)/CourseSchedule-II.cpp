
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);

        for(auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> que;

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topo;

        while(!que.empty()) {
            int node = que.front();
            que.pop();

            topo.push_back(node);

            for(auto it : adj[node]) {
                inDegree[it]--;

                if(inDegree[it] == 0) {
                    que.push(it);
                }
            }
        }

        if(topo.size() != n) return {};

        return topo;
    }
};

int main() {
    Solution obj;

    int n = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> ans = obj.canFinish(n, prerequisites);

    if(ans.empty() && n != 0) {
        cout << "Cycle detected!" << endl;
    }
    else {
        cout << "Course Order: ";

        for(auto x : ans) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}
