#include <bits/stdc++.h>
using namespace std;

// -------------------------
// MOCK API (VS Code ke liye)
// -------------------------
int bad = 4;   // yahan bad version set karo

bool isBadVersion(int version) {
    return version >= bad;
}

// -------------------------
// Solution
// -------------------------
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                high = mid;      // possible answer
            } else {
                low = mid + 1;   // right side
            }
        }

        return low;
    }
};

// -------------------------
// main function
// -------------------------
int main() {
    int n = 10;

    Solution obj;
    int ans = obj.firstBadVersion(n);

    cout << "First bad version is: " << ans << endl;

    return 0;
}