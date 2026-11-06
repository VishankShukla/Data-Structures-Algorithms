
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isCycle(int i, int j, int pi, int pj,
                 vector<vector<char>>& grid,
                 vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        visited[i][j] = 1;

        queue<pair<pair<int,int>,pair<int,int>>> que;
        que.push({{i,pi},{j,pj}});

        while(!que.empty()) {

            int row = que.front().first.first;
            int rowparent = que.front().first.second;

            int col = que.front().second.first;
            int colparent = que.front().second.second;

            que.pop();

            int dx[] = {-1,0,0,1};
            int dy[] = {0,-1,1,0};

            for(int k = 0; k < 4; k++) {

                int nr = row + dx[k];
                int nc = col + dy[k];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[row][col] == grid[nr][nc]) {

                    if(!visited[nr][nc]) {
                        que.push({{nr,row},{nc,col}});
                        visited[nr][nc] = 1;
                    }
                    else if(nr != rowparent || nc != colparent) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!visited[i][j] &&
                   isCycle(i, j, -1, -1, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter grid elements:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    if(obj.containsCycle(grid)) {
        cout << "Cycle Found" << endl;
    }
    else {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}
