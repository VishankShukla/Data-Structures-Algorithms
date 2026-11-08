
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& visited) {

        int n = board.size();
        int m = board[0].size();

        visited[i][j] = 1;

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        for(int k = 0; k < 4; k++) {
            int row = i + dx[k];
            int col = j + dy[k];

            if(row >= 0 && row < n &&
               col >= 0 && col < m &&
               board[row][col] == 'O' &&
               !visited[row][col]) {

                dfs(row, col, board, visited);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        if(n == 0) return;

        int m = board[0].size();
        if(m == 0) return;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // First and last row
        for(int i = 0; i < n; i += n-1) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    dfs(i, j, board, visited);
                }
            }
            if(n == 1) break;
        }

        // First and last column
        for(int j = 0; j < m; j += m-1) {
            for(int i = 0; i < n; i++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    dfs(i, j, board, visited);
                }
            }
            if(m == 1) break;
        }

        // Convert surrounded O to X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {

    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    cout << "Enter matrix (X/O):\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solve(board);

    cout << "\nFinal Matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
