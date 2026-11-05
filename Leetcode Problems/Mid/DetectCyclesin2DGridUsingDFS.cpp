
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

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        for(int k = 0; k < 4; k++) {

            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               grid[i][j] == grid[nr][nc]) {

                if(!visited[nr][nc]) {

                    if(isCycle(nr, nc, i, j,
                               grid, visited)) {
                        return true;
                    }

                }
                else if(pi != nr || pj != nc) {
                    return true;
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

    Solution obj;

    // Example 1
    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };

    bool ans = obj.containsCycle(grid);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}
