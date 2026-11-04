
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int coloum, int colour, int num) {
        image[row][coloum] = colour;

        int n = image.size();
        int m = image[0].size();

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = coloum + dy[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                image[nr][nc] == num) {

                dfs(image, nr, nc, colour, num);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num = image[sr][sc];

        if (num == color) return image;

        dfs(image, sr, sc, color, num);

        return image;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> result = obj.floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:" << endl;

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
