
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj,
                  vector<int>& visited, vector<int>& pathVisited) {

        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : adj[node]) {

            if(!visited[it]) {
                if(dfsCheck(it, adj, visited, pathVisited))
                    return true;
            }
            else if(pathVisited[it]) {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            int a = it[0];
            int b = it[1];

            adj[a].push_back(b);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfsCheck(i, adj, visited, pathVisited))
                    return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}
    };

    bool ans = obj.canFinish(numCourses, prerequisites);

    cout << boolalpha << ans << endl;

    return 0;
}
