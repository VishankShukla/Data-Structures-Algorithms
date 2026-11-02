
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjlist, vector<int>& visited) {
        visited[node] = 1;

        for(auto it : adjlist[node]) {
            if(!visited[it]) {
                dfs(it, adjlist, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        vector<vector<int>> adjlist(v);

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjlist[i].push_back(j);
                }
            }
        }

        vector<int> visited(v, 0);

        int count = 0;

        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, adjlist, visited);
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    Solution obj;

    cout << obj.findCircleNum(isConnected) << endl;

    return 0;
}
