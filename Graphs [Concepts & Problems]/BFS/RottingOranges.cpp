
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int coloum,
             vector<vector<int>>& grid,
             queue<pair<int,int>>& rotten,
             int& tfo) {

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < 4; i++) {

            int nr = row + dx[i];
            int nc = coloum + dy[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               grid[nr][nc] == 1) {

                rotten.push({nr, nc});
                grid[nr][nc] = 2;
                tfo--;
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int tfo = 0;
        queue<pair<int,int>> rotten;

        for(int row = 0; row < n; row++) {
            for(int coloum = 0; coloum < m; coloum++) {

                if(grid[row][coloum] == 2) {
                    rotten.push({row, coloum});
                }
                else if(grid[row][coloum] == 1) {
                    tfo++;
                }
            }
        }

        int minutes = 0;

        while(!rotten.empty() && tfo > 0) {

            int size = rotten.size();

            for(int i = 0; i < size; i++) {

                int row = rotten.front().first;
                int coloum = rotten.front().second;

                rotten.pop();

                bfs(row, coloum, grid, rotten, tfo);
            }

            minutes++;
        }

        return tfo > 0 ? -1 : minutes;
    }
};

// Main function for VS Code
int main() {

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution obj;

    int ans = obj.orangesRotting(grid);

    cout << "Minimum minutes: " << ans << endl;

    return 0;
}
