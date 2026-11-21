
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dis(n+1, INT_MAX);

        pq.push({0,k});
        dis[k] = 0;

        while(!pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dis[node]) continue;

            for(auto it : adj[node]){

                if(dis[it.first] > it.second + d){

                    dis[it.first] = it.second + d;

                    pq.push({it.second+d, it.first});
                }
            }
        }

        int m = 0;

        for(int i=1; i<=n; i++){

            if(dis[i] == INT_MAX) return -1;

            m = max(m, dis[i]);
        }

        return m;
    }
};

int main() {

    int n = 4;
    int k = 2;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    Solution obj;

    int ans = obj.networkDelayTime(times, n, k);

    cout << "Network Delay Time: " << ans << endl;

    return 0;
}
