#include <bits/stdc++.h>
using namespace std;

int pick = 6;

int guess(int num) {
    if (num > pick) return -1;
    else if (num < pick) return 1;
    else return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == -1) high = mid - 1;
            else if (res == 1) low = mid + 1;
            else return mid;
        }

        return -1;
    }
};

int main() {
    int n = 10;

    Solution obj;
    int ans = obj.guessNumber(n);

    cout << "Picked number is: " << ans << endl;

    return 0;
}