#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> minPrice(n, INT_MAX);

        queue<pair<int,pair<int,int>>> que;

        que.push({0, {src, 0}});
        minPrice[src] = 0;

        while(!que.empty()) {

            auto it = que.front();
            que.pop();

            int node = it.second.first;
            int edw = it.second.second;
            int stop = it.first;

            if(stop > k) continue;

            for(auto iter : adj[node]) {

                if(minPrice[iter.first] > edw + iter.second && stop <= k) {

                    minPrice[iter.first] = edw + iter.second;

                    que.push({
                        stop + 1,
                        {iter.first, minPrice[iter.first]}
                    });
                }
            }
        }

        if(minPrice[dst] == INT_MAX) return -1;

        return minPrice[dst];
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    for(int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    Solution obj;

    cout << obj.findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}
