#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int leftMax = 0, rightMax = 0;
        int n = height.size();
        int l = 0, r = n - 1;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < leftMax)
                    total += leftMax - height[l];
                else
                    leftMax = height[l];
                l++;
            } else {
                if (height[r] < rightMax)
                    total += rightMax - height[r];
                else
                    rightMax = height[r];
                r--;
            }
        }

        return total;
    }
};

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    cout << "Trapped Rain Water = " << obj.trap(height) << endl;

    return 0;
}