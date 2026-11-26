#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    pq.push({1, {0, 0}});
    dis[0][0] = 1;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!pq.empty()) {
        int count = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        pq.pop();

        if (dis[i][j] < count)
            continue;

        if (i == n-1 && j == n-1)
            return count;

        for (int k = 0; k < 8; k++) {
            int row = i + dx[k];
            int col = j + dy[k];

            if (row >= 0 && col >= 0 &&
                row < n && col < n &&
                grid[row][col] == 0 &&
                dis[row][col] > count + 1) {

                dis[row][col] = count + 1;
                pq.push({dis[row][col], {row, col}});
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter grid size: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter grid elements (0 or 1):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Shortest Path: "
         << shortestPathBinaryMatrix(grid) << endl;

    return 0;
}
