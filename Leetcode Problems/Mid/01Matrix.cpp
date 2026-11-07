
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> que;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!mat[i][j]) {
                    que.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};

        while(!que.empty()) {

            int row = que.front().first.first;
            int col = que.front().first.second;
            int steps = que.front().second;

            ans[row][col] = steps;
            que.pop();

            for(int i = 0; i < 4; i++) {

                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    que.push({{nr,nc}, steps + 1});
                }
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    Solution obj;

    vector<vector<int>> result = obj.updateMatrix(mat);

    cout << "Output:" << endl;

    for(auto &row : result) {
        for(auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
