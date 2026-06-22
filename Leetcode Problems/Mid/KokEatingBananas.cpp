#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;

            for (int bananas : piles) {
                hours += (bananas + mid - 1LL) / mid;
            }

            if (hours <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution obj;
    cout << obj.minEatingSpeed(piles, h) << endl;

    return 0;
}