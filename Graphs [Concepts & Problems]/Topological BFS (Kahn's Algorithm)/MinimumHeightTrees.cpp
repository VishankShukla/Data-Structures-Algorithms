
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            inDegree[v]++;

            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> que;

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 1) {
                que.push(i);
            }
        }

        int remaining = n;

        while(remaining > 2) {
            int size = que.size();
            remaining = remaining - size;

            for(int i = 0; i < size; i++) {
                int node = que.front();
                que.pop();

                for(auto it : adj[node]) {
                    inDegree[it]--;

                    if(inDegree[it] == 1) {
                        que.push(it);
                    }
                }
            }
        }

        vector<int> ans;

        while(!que.empty()) {
            ans.push_back(que.front());
            que.pop();
        }

        return ans;
    }
};

int main() {
    int n = 6;

    vector<vector<int>> edges = {
        {3, 0},
        {3, 1},
        {3, 2},
        {3, 4},
        {5, 4}
    };

    Solution obj;

    vector<int> ans = obj.findMinHeightTrees(n, edges);

    cout << "Minimum Height Tree Roots: ";

    for(auto it : ans) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
