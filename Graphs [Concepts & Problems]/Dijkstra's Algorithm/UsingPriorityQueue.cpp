#include <bits/stdc++.h>
using namespace std;

void minDis(int V, vector<vector<pair<int,int>>>& adj, int src, vector<int>& dis) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dis[node]) continue;

        for(auto it: adj[node]){
            if(dis[it.first] > it.second+d){
                dis[it.first] = it.second+d;
                pq.push({it.second+d,it.first});
            }
        }
    }
}

int main() {

    int V = 5;

    vector<vector<pair<int,int>>> adj(V + 1);
    vector<int> dis(V+1,INT_MAX);

    adj[1].push_back({2, 4});
    adj[1].push_back({3, 1});

    adj[3].push_back({2, 2});
    adj[2].push_back({4, 1});

    adj[3].push_back({4, 5});
    adj[4].push_back({5, 3});

    int src = 1;

    minDis(V, adj, src, dis);

    for(int i=1; i<=V; i++){
        cout <<src<< "->"<< i << "-" << dis[i] << endl;
    }

    return 0;
}
