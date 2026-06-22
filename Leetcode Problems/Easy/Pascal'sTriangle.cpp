#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        nums.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> n;
            const vector<int>& ith = nums[i - 1];

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    n.push_back(1);
                else
                    n.push_back(ith[j - 1] + ith[j]);
            }

            nums.push_back(n);
        }

        return nums;
    }
};

int main() {
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution obj;
    vector<vector<int>> result = obj.generate(numRows);

    for (auto &row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}