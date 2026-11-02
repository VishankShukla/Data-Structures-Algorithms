#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = 0, totalCost = 0;
        int start = 0, currGas = 0;

        for(int i = 0; i < n; i++) {

            totalGas += gas[i];
            totalCost += cost[i];

            currGas += (gas[i] - cost[i]);

            if(currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }

        return totalGas < totalCost ? -1 : start;
    }
};

int main() {

    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    vector<int> gas(n), cost(n);

    cout << "Enter gas array: ";
    for(int i = 0; i < n; i++) {
        cin >> gas[i];
    }

    cout << "Enter cost array: ";
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    Solution obj;

    int ans = obj.canCompleteCircuit(gas, cost);

    cout << "Starting Station Index: " << ans << endl;

    return 0;
}
