#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> visited;

        vector<int> para = {2, 3, 5};

        pq.push(1);
        visited.insert(1);

        long long ans = 1;

        for (int i = 0; i < n; i++) {

            ans = pq.top();
            pq.pop();

            for (int num : para) {

                long long next = ans * num;

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    pq.push(next);
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Nth Ugly Number = " << obj.nthUglyNumber(n) << endl;

    return 0;
}