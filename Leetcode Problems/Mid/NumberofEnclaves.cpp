
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = 0;

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        for(int k = 0; k < 4; k++) {
            int row = i + dx[k];
            int col = j + dy[k];

            if(row >= 0 && row < n &&
               col >= 0 && col < m &&
               grid[row][col] == 1) {
                dfs(row, col, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // First and last row
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1)
                dfs(0, i, grid);

            if(n > 1 && grid[n-1][i] == 1)
                dfs(n-1, i, grid);
        }

        // First and last column
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1)
                dfs(i, 0, grid);

            if(m > 1 && grid[i][m-1] == 1)
                dfs(i, m-1, grid);
        }

        // Count remaining land cells
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    cout << obj.numEnclaves(grid) << endl;

    return 0;
}
