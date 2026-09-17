#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        int i = 0;
        int j = 0;

        int currsum = 0;

        vector<int> minlentillidx(n, INT_MAX);

        int bestlen = INT_MAX;
        int result = INT_MAX;

        while (j < n) {

            currsum += arr[j];

            while (currsum > target) {
                currsum -= arr[i];
                i++;
            }

            if (currsum == target) {

                int len = j - i + 1;

                if (i > 0 && minlentillidx[i - 1] != INT_MAX) {

                    result = min(result,
                                 len + minlentillidx[i - 1]);
                }

                bestlen = min(bestlen, len);
            }

            minlentillidx[j] = bestlen;

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {3, 2, 2, 4, 3};

    int target = 3;

    int ans = obj.minSumOfLengths(arr, target);

    cout << "Answer: " << ans << endl;

    return 0;
}