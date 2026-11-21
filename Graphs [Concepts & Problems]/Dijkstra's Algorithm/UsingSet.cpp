#include <bits/stdc++.h>
using namespace std;

void minDis(int V, vector<vector<pair<int,int>>>& adj, int src, vector<int>& dis) {
    set<pair<int,int>> s;
    s.insert({0,src});
    dis[src]=0;

    while(!s.empty()){
        auto it = *(s.begin());

        int d = it.first;
        int node = it.second;
        s.erase({d,node});

        if(d > dis[node]) continue;

        for(auto ite: adj[node]){
            if(dis[ite.first] > ite.second+d){
                if(dis[ite.first] != INT_MAX) s.erase({dis[ite.first],ite.first});
                dis[ite.first] = ite.second+d;
                s.insert({ite.second+d,ite.first});
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
