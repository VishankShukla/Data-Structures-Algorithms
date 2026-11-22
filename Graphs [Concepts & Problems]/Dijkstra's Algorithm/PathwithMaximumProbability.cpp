#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < succProb.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> succp(n, 0.0);

        priority_queue<pair<double,int>> que;

        que.push({1.0, start_node});
        succp[start_node] = 1.0;

        while(!que.empty()) {

            double tp = que.top().first;
            int node = que.top().second;
            que.pop();

            if(tp < succp[node]) continue;

            if(node == end_node) return tp;

            for(auto it : adj[node]) {

                if(succp[it.first] < tp * it.second) {

                    succp[it.first] = tp * it.second;

                    que.push({succp[it.first], it.first});
                }
            }
        }

        return 0.0;
    }
};

int main() {

    Solution obj;

    int n = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2}
    };

    vector<double> succProb = {
        0.5, 0.5, 0.2
    };

    int start_node = 0;
    int end_node = 2;

    double ans = obj.maxProbability(
        n, edges, succProb, start_node, end_node
    );

    cout << fixed << setprecision(5);
    cout << "Maximum Probability: " << ans << endl;

    return 0;
}
