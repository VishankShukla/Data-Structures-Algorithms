
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == '1' &&
                   !visited[nr][nc]) {

                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int isIsland = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(grid[row][col] == '1' && !visited[row][col]) {
                    isIsland++;
                    bfs(row, col, grid, visited);
                }
            }
        }

        return isIsland;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    cout << obj.numIslands(grid) << endl;

    return 0;
}
