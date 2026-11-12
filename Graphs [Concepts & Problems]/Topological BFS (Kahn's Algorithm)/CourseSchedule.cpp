
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
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

        int cnt = 0;

        while(!que.empty()) {
            int node = que.front();
            que.pop();
            cnt++;

            for(auto it : adj[node]) {
                inDegree[it]--;

                if(inDegree[it] == 0) {
                    que.push(it);
                }
            }
        }

        return cnt == n;
    }
};

int main() {
    Solution obj;

    int n = 2;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}
    };

    bool ans = obj.canFinish(n, prerequisites);

    if(ans) {
        cout << "All courses can be completed" << endl;
    }
    else {
        cout << "All courses cannot be completed" << endl;
    }

    return 0;
}
