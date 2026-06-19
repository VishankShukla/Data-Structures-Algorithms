#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return matrix in spiral order
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Vector to store final spiral order result
        vector<int> result;

        // Get number of rows and columns
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        // Traverse the matrix in spiral order
        while(top <= bottom && left <= right) {

            // Traverse from left to right across the top row
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move top boundary down

            // Traverse from top to bottom on the right column
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move right boundary left

            // Check if there are rows remaining
            if(top <= bottom) {
                // Traverse from right to left on the bottom row
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move bottom boundary up
            }

            // Check if there are columns remaining
            if(left <= right) {
                // Traverse from bottom to top on the left column
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move left boundary right
            }
        }

        // Return the final spiral order
        return result;
    }
};

// Driver code
int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    vector<int> result = obj.spiralOrder(matrix);

    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}
